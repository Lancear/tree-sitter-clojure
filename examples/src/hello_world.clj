(ns hello-world
  (:gen-class))

;;; comments are supported now ;;;

(def favouriteNumber 2r10011001)
(def crazyNumber -420.e+69M)

(defn -main []
  (println 
    (str 
      "My favourite number is " 
      favouriteNumber 
      "!\nWtf is this carzy number " 
      crazyNumber 
      "?\nTo " 
      ##Inf
      " and beyond!\n"
      5/4
      " Devs like clojure!")))
