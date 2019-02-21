

public class Main_171044053<E> {
	public static void main(String args[]){
		LinkedList<String> LLS = new LinkedList<String>();
		LinkedList<Integer> LLI = new LinkedList<Integer>();

		TestString(LLS);
		TestInt(LLI);
		
		ArrayList<String> ALS = new ArrayList<String>();
		ArrayList<Integer> ALI = new ArrayList<Integer>();

		TestString(ALS);
		TestInt(ALI);
	
		HashSet<String> HSS = new HashSet<String>();
		HashSet<Integer> HSI = new HashSet<Integer>();

		TestString(HSS);
		TestInt(HSI);

	}
	
	@SuppressWarnings("rawtypes")
	public static void TestInt(Collection<Integer> collection ){
		
		System.out.println("Test for Integer " + collection.getClass().getSimpleName());
		
		int[] myInt = {1,5,2,4,7,8,3,9,6};
				
		ArrayList<Integer> addArrayList = new ArrayList<Integer>();
		HashSet<Integer> addHashSet = new HashSet<Integer>();
		LinkedList<Integer> addLinkedList = new LinkedList<Integer>();
		ArrayList<Integer> remArrayList = new ArrayList<Integer>();
		HashSet<Integer> remHashSet = new HashSet<Integer>();
		LinkedList<Integer> remLinkedList = new LinkedList<Integer>();
		for(int i = 1 ; i < 3 ; ++i ){
			addArrayList.add((i*10)+1);
			addHashSet.add((i*20)+2);
			addLinkedList.add((i*30)+3);
			
			remArrayList.add((i+1));
			remHashSet.add((i+3));
			remLinkedList.add((i+5));
		}
		
		//Test for add
		
		for(int i = 0 ; i < myInt.length ; ++i ){
			collection.add(myInt[i]);
		}
		
		System.out.println("After add method");
		printCollection(collection);
		
		collection.addAll(addArrayList);
		collection.addAll(addHashSet);
		collection.addAll(addLinkedList);

		
		System.out.println("After addAll method");
		printCollection(collection);
		
		System.out.println("Does this collection contain 1?");
		System.out.println(collection.contains(1));
		
		collection.remove(1);

		System.out.println("After removing 1");
		printCollection(collection);
		
		System.out.println("Does this collection contain a collection with 32, 43?");
		System.out.println(collection.containsAll(addLinkedList));

		System.out.println("RetainAll function with 1, 21, 32");
		ArrayList<Integer> retainAll = new ArrayList<Integer>();
		retainAll.add(1);
		retainAll.add(21);
		retainAll.add(32);
		
		Collection<Integer> intersection = collection.retainAll(retainAll);
		printCollection(intersection);

		collection.removeAll(remArrayList);
		collection.removeAll(remHashSet);
		collection.removeAll(remLinkedList);
		
		System.out.println("After removing collection with 2, 3, 4, 5, 6, 7");
		printCollection(collection);
		
		System.out.println("Size before clear function");
		System.out.println(collection.size());
		
		collection.clear();
		
		System.out.println("Size after clear function");
		System.out.println(collection.size());

		System.out.println("Is collection empty");
		System.out.println(collection.isEmpty());
		
		
	    try{
	        collection.remove(2);
	    }
	    catch (Exception e){
	        System.out.print(e);

	    }
	    
	    if(collection.getClass().getSimpleName() == "HashSet"){
	    	collection.add(2);
	    	try{
	    		collection.add(2);
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    }
		
	    if(collection.getClass().getSimpleName() == "LinkedList"){
	    	collection.addAll(addArrayList);
    		collection.offer(4);
    		
    		System.out.println("Head of linkedlist " + collection.element());

	    	try{
	    		collection.remove(4);
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    	try{
	    		collection.clear();
	    		collection.poll();
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    }
	    
	    System.out.println("Iterator tests");
	    collection.clear();
	    collection.addAll(addLinkedList);
	    
	    System.out.println("Current collection");
	    printCollection(collection);
	    
	    Iterator it = collection.iterator();
	    
	    System.out.println("Current element returned by iterator");
	    System.out.println(it.elementgetter());
	    
	    System.out.println("Does iterator has next?");
	    System.out.println(it.hasNext());

	    System.out.println("Move iterator next");
	    System.out.println(it.next());

	    System.out.println("Remove current element ");
	    it.remove();
	    System.out.println(it.elementgetter());
	    
	    collection.clear();
	    
	    try{
	    	it.remove();
	    }catch(Exception e){
	    	System.out.print(e);
	    }
	    
	    try{
	    	it.next();
	    }catch(Exception e){
	    	System.out.print(e);
	    }
	
	}
	
	@SuppressWarnings("rawtypes")
	public static void TestString(Collection<String> collection ){
		
		System.out.println("Test for String " + collection.getClass().getSimpleName());

		
		String[] myStr = {"OOP", "YSA", "Deadpool", "Logan", "Saliha", "Ozi",
				"Tavuk", "Köfte", "Tantuni", "Aa"};

		ArrayList<String> addArrayList = new ArrayList<String>();
		HashSet<String> addHashSet = new HashSet<String>();
		LinkedList<String> addLinkedList = new LinkedList<String>();
		ArrayList<String> remArrayList = new ArrayList<String>();
		HashSet<String> remHashSet = new HashSet<String>();
		LinkedList<String> remLinkedList = new LinkedList<String>();

			addArrayList.add("Ab");
			addArrayList.add("Ac");

			addHashSet.add("Ad");
			addHashSet.add("Af");

			addLinkedList.add("Ag");
			addLinkedList.add("Beyti");

			
			remArrayList = addArrayList;
			remHashSet = addHashSet;
			remLinkedList = addLinkedList;
		
		
		//Test for add
		
		for(int i = 0 ; i < myStr.length ; ++i ){
			collection.add(myStr[i]);
		}
		
		System.out.println("After add method");
		printCollection(collection);
		
		collection.addAll(addArrayList);
		collection.addAll(addHashSet);
		collection.addAll(addLinkedList);

		
		System.out.println("After addAll method");
		printCollection(collection);
		
		System.out.println("Does this collection contain Aa?");
		System.out.println(collection.contains("Aa"));
		
		collection.remove("Aa");

		System.out.println("After removing Aa");
		printCollection(collection);
		
		System.out.println("Does this collection contain a collection with Af Ag?");
		System.out.println(collection.containsAll(addLinkedList));

		System.out.println("RetainAll function with Beyti, Deadpool, Köfte");
		ArrayList<String> retainAll = new ArrayList<String>();
		retainAll.add("Beyti");
		retainAll.add("Deadpool");
		retainAll.add("Köfte");
		
		Collection<String> intersection = collection.retainAll(retainAll);
		printCollection(intersection);

		collection.removeAll(remArrayList);
		collection.removeAll(remHashSet);
		collection.removeAll(remLinkedList);
		
		System.out.println("After removing collection with Beyti,Ab,Ac,Ad,Af,Ag");
		printCollection(collection);
		
		System.out.println("Size before clear function");
		System.out.println(collection.size());
		
		collection.clear();
		
		System.out.println("Size after clear function");
		System.out.println(collection.size());

		System.out.println("Is collection empty");
		System.out.println(collection.isEmpty());
		
	    try{
	        collection.remove("Adana");
	    }
	    catch (Exception e){
	        System.out.print(e);
	    }
	    
	    if(collection.getClass().getSimpleName() == "HashSet"){
	    	collection.add("A");
	    	try{
	    		collection.add("A");
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    }
		
	    if(collection.getClass().getSimpleName() == "LinkedList"){
	    	collection.addAll(addArrayList);
    		collection.offer("Z");
    		
    		System.out.println("Head of linkedlist " + collection.element());

	    	try{
	    		collection.remove("Z");
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    	try{
	    		collection.clear();
	    		collection.poll();
	    	}
	    	catch (Exception e){
	    		System.out.print(e);
	    	}
	    }
	    
	    
	    System.out.println("Iterator tests");
	    collection.clear();
	    collection.addAll(addLinkedList);
	    
	    System.out.println("Current collection");
	    printCollection(collection);
	    
	    Iterator it = collection.iterator();
	    
	    System.out.println("Current element returned by iterator");
	    System.out.println(it.elementgetter());
	    
	    System.out.println("Does iterator has next?");
	    System.out.println(it.hasNext());

	    System.out.println("Move iterator next");
	    System.out.println(it.next());

	    System.out.println("Remove current element ");
	    it.remove();
	    System.out.println(it.elementgetter());
	    
	    collection.clear();
	    
	    try{
	    	it.remove();
	    }catch(Exception e){
	    	System.out.print(e);
	    }
	    
	    try{
	    	it.next();
	    }catch(Exception e){
	    	System.out.print(e);
	    }
	   
	
	}
	
	//print functions for test
	@SuppressWarnings("rawtypes")
	private static void printCollection(Collection collection){

		for(int i = 0; i < collection.size(); ++i ){
			System.out.print(collection.at(i) + " ")  ;
		}
		System.out.println()  ;
	}
	

}
