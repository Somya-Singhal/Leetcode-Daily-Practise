class Food implements Comparable<Food>{
    String name, cuisine;
    int rating;
    Food(String name, String cuisine, int rating){
        this.name = name;
        this.cuisine = cuisine;
        this.rating = rating;
    }
    
    String getName(){
        return name;
    }
    String getCuisine(){
        return cuisine;
    }
    
    int getRating(){
        return rating;
    }
    
    void setRating(int rating){
        this.rating = rating;
    }
    
    @Override
    public int compareTo(Food other){
        if(rating == other.rating){
            return name.compareTo(other.name);
        }
        return -1*Integer.compare(rating,other.rating);
    }
}

class FoodRepository{
    HashMap<String, Food>foodMap;
    
    Map<String, PriorityQueue<Food>>cuisineFoodMap;
    FoodRepository(){
        foodMap = new HashMap<>();
        cuisineFoodMap = new HashMap<>();
    }
    
    void addFood(Food food){
        foodMap.put(food.getName(), food);
        cuisineFoodMap.computeIfAbsent(food.getCuisine(), k-> new PriorityQueue<>()).add(new Food(food.getName(), food.getCuisine(), food.getRating()));
    }
    
    Food getFood(String name){
        return foodMap.get(name);
    }
    
    PriorityQueue<Food> getHighestRatedFood(String cuisine){
        return cuisineFoodMap.get(cuisine);
    }
    
    String highestRatingFood(String cuisine){
        
        Iterator<Food> it = cuisineFoodMap.get(cuisine).iterator();
        // while(it.hasNext()){
        //     Food getFood = it.next();
        //     // System.out.println(it.next());
        //     System.out.println("name: "+getFood.getName()+", cuisine: "+getFood.getCuisine()+", rating: "+getFood.getRating());
        // }
        // System.out.println("//////////////////");
        // for(Map.Entry<String,Food>mapEle: foodMap.entrySet()){
        //     String foodName=mapEle.getKey();
        //     Food food = mapEle.getValue();
        //     System.out.println("name: "+food.getName()+", cuisine: "+food.getCuisine()+", rating: "+food.getRating());
        // }
        // System.out.println("/////////Printing Map/////////");
       Food highestRated = cuisineFoodMap.get(cuisine).peek();
       // String highestRatedFoodItem = highestRated.getName();
        // System.out.println("name: "+highestRated.getName()+", cuisine: "+highestRated.getCuisine()+", rating: "+highestRated.getRating());
        // System.out.println("/////Is it there?///////");
        // System.out.println("rating: "+foodMap.get(highestRated.getName()).getRating());
        // System.out.println("/////Lets find::://///");
       while(foodMap.get(highestRated.getName()).getRating()!=highestRated.rating){
           // System.out.println("I m here...");
           cuisineFoodMap.get(cuisine).poll();
           highestRated = cuisineFoodMap.get(cuisine).peek();
       //     System.out.println("name: "+highestRated.getName()+", rating: "+highestRated.getRating()+"map rating: "+foodMap.get(highestRated.getName()).getRating());
       //     System.out.println("**********");
       }
       return highestRated.getName();
    }
}

class FoodRatings {

    FoodRepository foodRepository;
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodRepository = new FoodRepository();
        int n= foods.length;
        for(int i=0;i<n;i++){
            Food food = new Food(foods[i], cuisines[i], ratings[i]);
            foodRepository.addFood(food);
        }
        
    }
    
    public void changeRating(String food, int newRating) {
        Food createdFood = foodRepository.getFood(food);
        createdFood.setRating(newRating);
        // Food newFood = new Food()
        PriorityQueue<Food> highestRatedFoodQueue = foodRepository.getHighestRatedFood(createdFood.getCuisine());
        highestRatedFoodQueue.add(new Food(food, createdFood.getCuisine(), newRating));
        
    }
    
    public String highestRated(String cuisine) {
        String highestRatingFood = foodRepository.highestRatingFood(cuisine);
        return highestRatingFood;
    }
}


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */