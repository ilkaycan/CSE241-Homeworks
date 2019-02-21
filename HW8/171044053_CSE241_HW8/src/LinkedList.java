/**
 * Implemets List and Queue methods 
 * LinkedList is generic
 * @author İlkay CAN - 171044053
 *
 * @param <E> defines type of data
 */

import java.util.Arrays;


public class LinkedList<E> implements List<E>, Queue<E> {
	
	private E[] data;

	//Constructor
	
	/**
	 * Constructor
	 */
	@SuppressWarnings("unchecked")
	public LinkedList(){
		data = (E[])new Object[0];
	}
	
    //This function creates an Iterator for collection
	public Iterator <E> iterator(){
		return new Iterator<E>(data);
	}
	
    //Adds given element to the end of the collection
	@SuppressWarnings("unchecked")
	public boolean add (E e){
		E temp[] = (E[])new Object[data.length + 1];
        System.arraycopy(data, 0, temp, 0, data.length);
        temp[data.length] = e;
        data = temp;

        Arrays.sort(data);
        	
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
		for(E i : data){
            if( e == i){
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
	 * @throws IllegalArgumentException if given element does not exist or given element is not at head
	 */
	@SuppressWarnings("unchecked")
	public boolean remove(E e) throws IllegalArgumentException{
	    if(this.contains(e)){
	        if(e == data[0]) {
		    	E temp[] = (E[])new Object[data.length - 1];
	        	System.arraycopy(data, 1, temp, 0, temp.length);
	        	data = temp;
	        } else{
	            throw new IllegalArgumentException("This element can not be removed because this collection is FIFO\n");
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

	      LinkedList<E> temp = new LinkedList<E>();

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
	
	//returns head
	
	/**
	 * 
	 * @return element in first index
	 * @throws IndexOutOfBoundsException if Collection is empty
	 */
	
	public E element() throws IndexOutOfBoundsException{
		if(data.length != 0){
			return data[0];
		} else {
			throw new IndexOutOfBoundsException("This colleciton is empty");
		}
	}
	
	//Adds given value to Collection
	public boolean offer(E e){
        this.add(e);
  		return true;
	}
	
	//Removes last element
	
	/**
	 * removes last element
	 * @return last element
	 * @throws IndexOutOfBoundsException if Collection is already empty
	 */
	public E poll()throws IndexOutOfBoundsException{
        if(this.isEmpty()){
            throw new IndexOutOfBoundsException("This collection is empty!!\n");
        } else {
        	this.remove(data[0]);
        }
        return data[0];
	}
	
	//returns element in the given index
	public E at(int index){
		return data[index];
	}
}
