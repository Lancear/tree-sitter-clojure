(ns hello-world
  (:gen-class))

;;; comments are supported now ;;;

(def favouriteNumber 2r10011001)
(def crazyNumber -420.e+69M)
(def hex 0xcafeBABE)
(def person {:name {:first "John", :middle "Jacob", :last "Jingleheimerschmidt"}})
(def hexChars '(\a, \b \c \d \e, \f))
(def trueRandomness #{"kurt vonnegut" 20 :icicle})

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
      \λ
      \tab
      5/4
      " devs like clojure and this is 100% "
      true
      "!")))
