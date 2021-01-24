;; I do not know what this mess is
;; Just found it in an old clojure playground of mine
;; Only using it for testing the parsing LUL

(ns core
  (:require [org.httpkit.server :refer [run-server]]
            [ring.util.codec :refer [form-decode]]
            [clojure.string :as s]))

(def stop-server (atom nil))

(def data 
  {"channels" 
   {"0" {"users" {"0" {"name" "pete", "gender" "male"}
                  "1" {"name" "peter", "gender" "male"}
                  "2" {"name" "lisa", "gender" "female"}}}}})

; routing api
(def route [:GET ["channels" :id "users" #{:name :gender}]])


(defmacro build-get-route [collName]
  (let [data (gensym)]
  `(defn ~(symbol (str "get-" collName)) [~data] (get ~data ~collName))))

(defmacro build-get-by-id-route [itemName]
  (let [data (gensym), id (gensym)]
    `(defn ~(symbol (str "get-" itemName "-by-id")) [~data ~id] (get ~data ~id))))

(defmacro build-filter-route [collName]
  (let [data (gensym), key-val (gensym)]
    `(defn ~(symbol (str "filter-" collName)) [~data ~key-val] (filter #(= (get % (first ~key-val)) (second ~key-val)) ~data))))



(defn get-channels [data] (get data "channels")) ; done
(defn get-channel-by-id [channels id] (get channels id)) ; done
(defn get-channel-users [channel] (get channel "users")) ; done
(defn filter-channel-users [users keyval] (filter #(= (get % (first keyval)) (second keyval)) users))

; GET /channels/0/users?gender=male&name=pete
(->
 data
 get-channels
 (get-channel-by-id 0)
 get-channel-users
 vals
 (filter-channel-users ["gender" "male"])
 (filter-channel-users ["name" "pete"]))

(handler {:uri "/channels/0/users" :query-string "gender=male&name=pete"})


(defn handler
  "Handles the http requests"
  [req]
  (do 
    (println "yeah!")
    (let [get-data (reduce #(get %1 %2) data (rest (s/split (:uri req) #"[/]")))
          get-vals (vals get-data)
          f-filter-data (fn [data query] (let [q (s/split query #"[=]")] (filter #(= (get % (first q)) (second q)) data)))
          filter-data (reduce f-filter-data get-vals (s/split (:query-string req) #"[&]"))]
      {:status 200
       :body filter-data})))



(defn -main
  "Starts an http server"
  [& args]
  (do 
    (reset! stop-server (run-server handler {:port 80}))
    (println "Server running at port 80")))
