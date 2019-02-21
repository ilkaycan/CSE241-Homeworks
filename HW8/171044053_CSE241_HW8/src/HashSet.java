/**
 * Implemets Set methods
 * HashSet is generic
 * @author İlkay CAN - 171044053
 *
 * @param <E> defines type of data
 */
public class HashSet<E> implements Set <E>{
	
	private E[] data;
	
	//Constructor
	
	/**
	 * Constructor
	 */
	@SuppressWarnings("unchecked")
	public HashSet(){
		data = (E[])new Object[0];
	}
	
    //This function creates an Iterator for collection
	public Iterator <E> iterator(){
		return new Iterator<E>(data);
	}
	
    //Adds given element to the end of the collection
	
	/**
	 * This function adds given value to collection
	 * @param e
	 * @return true if add is succesfull
	 * @throws IllegalArgumentException if given value already exists in collection
	 */
	@SuppressWarnings("unchecked")
	public boolean add (E e) throws IllegalArgumentException{
		if( !(this.contains(e))){
	    	E temp[] = (E[])new Object[data.length + 1];
        	System.arraycopy(data, 0, temp, 0, data.length);
        	temp[data.length] = e;
        	data = temp;

		}else {
            throw new IllegalArgumentException("This value is already exists in hashset");
        }
		return true;
	}
	
    //Adds all of given collection to the end of this collection
	public boolean addAll(Collection<E> c){

		for(int i = 0 ; i < c.size() ; ++i) {
            this.add(c.at(i));
        }
        return true;	
    }
	
    //Makes collection empty
	@SuppressWarnings("unchecked")
	public void clear(){
    	E temp[] = (E[])new Object[0];
    	data = temp;
	}
	
    //Checks if given element exist in this collection
	public boolean contains(E e){
		for(int i = 0; i < data.length; ++i){
            if( e.equals(data[i])){
                return true;
            }
        }

        return false;
	}
	
    //Checks if all of given collection exists in this collection
	public boolean containsAll(Collection<E> c){
        for(int i = 0; i < c.size(); ++i){
            if(!(this.contains(c.at(i)))) {
                return false;
            }
        }

        return true;
	}
	
    //Checks if this collection is empty
	public boolean isEmpty(){
        if (data.length == 0) {
            return true;
        } else {
            return false;
        }
	}
	
    //Removes the given element if it exists in this collection
	
	/**
	 * removes given element 
	 * @param e
	 * @return true if remove is succesfull
	 * @throws IllegalArgumentException if given element does not exist
	 */
	@SuppressWarnings("unchecked")
	public boolean remove(E e) throws IllegalArgumentException{
        if(this.contains(e)){
    		for(int i = 0; i < data.length; ++i){
    			if(data[i].equals( e)){
    		    	E temp[] = (E[])new Object[data.length - 1];
    	        	System.arraycopy(data, 0, temp, 0, i);
    	        	System.arraycopy(data, i+1, temp, i, temp.length-i);
    	        	data = temp;
    			}
    		}
        } else {
            throw new IllegalArgumentException("This element does not exist!!\n");
        }
        return true;
	}
	
    //Removes all of the given element if it exists in this collection
	public boolean removeAll(Collection<E> c){
        for(int i = 0; i < c.size(); ++i){
            this.remove(c.at(i));
        }
        return true;
	}
	
    //Returns intersection
	public Collection<E> retainAll( Collection<E> c){

	      HashSet<E> temp = new HashSet<E>();

	      if(!(c.isEmpty())){
	    	  for(E i : data){
	    		  if(c.contains(i)){
	    			  temp.add(i);
	    		  }
	    	  }
	      }
	     
	      return temp;
	}
	
    //Returns size of this collection
	public int size(){
		return data.length;
	}

	//returns element in the given index
	public E at(int index){
		return data[index];
	}
	
	public E element(){
		/*INTENTIONALLY EMPTY*/
		return data[0];
	}
	public boolean offer(E e){
		/*INTENTIONALLY EMPTY*/
		return true;
	}
	public E poll(){
		/*INTENTIONALLY EMPTY*/
		return data[0];
	}
	
	

}
