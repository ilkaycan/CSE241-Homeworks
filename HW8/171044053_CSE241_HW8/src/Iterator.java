/**
 * This is a generic iterator class for my own collection 
 * @author İlkay CAN - 171044053
 *
 * @param <E> defines type of data
 */
public class Iterator<E>{
	private E[] container;
	private int sizeCheck;
	private int currentIndex;
	
    //Constructor
	
	/**
	 * Constructor
	 * @param containerVariable
	 */
	public Iterator(E[] containerVariable){
		sizeCheck = 1;
		container = containerVariable.clone();
		currentIndex = sizeCheck - 1;
	}
	
    //This function returns true if iterator has a next
	
	/**
	 * Checks if iterator has next 
	 * @return true if next exists
	 */
	public boolean hasNext(){
		if(container.length == 0){
			return false;
		}else if(container.length != sizeCheck){
			return true;
		} else {
			return false;
		}
	}

	
    //This function makes iterator move forward and returns the element

	/**
	 * Takes iterator to one element forward
	 * @return current element after next
	 * @throws IndexOutOfBoundsException if there exists no next
	 */
    E next() throws IndexOutOfBoundsException{
        if(this.hasNext()) {
            ++sizeCheck;
            ++currentIndex;
        } else {
            throw new IndexOutOfBoundsException("Next element does not exist!!");
        }

        return container[currentIndex];
    }
    //This function returns the current element returned by this iterator
    
    /**
     * 
     * @return current element that iterator shows
     * @throws IndexOutOfBoundsException if collection is empty
     */
    E elementgetter() throws IndexOutOfBoundsException {

        if(0 == container.length || currentIndex >= container.length){
        	throw new IndexOutOfBoundsException("This container is empty!!");
        }
        return container[currentIndex];
    }
    
    //This function removes the last element returned by this iterator
    
    /**
     * removes current element
     * @throws IndexOutOfBoundsException ifcollection is empty
     */
    @SuppressWarnings("unchecked")
	void remove() throws IndexOutOfBoundsException{
    	E temp[] = (E[])new Object[container.length - 1];
    	if(container.length == 1){
    		container = temp;
    		--sizeCheck;
    	} if(container.length != 0){
    		if(this.hasNext() == false){
            	System.arraycopy(container, 0, temp, 0, currentIndex);
            	container = temp;
        		--currentIndex;
        		--sizeCheck;
    		}else {
    			System.arraycopy(container, 0, temp, 0, currentIndex);
        		System.arraycopy(container, currentIndex+1, temp, currentIndex, temp.length-currentIndex);
        		container = temp;
    		}
        } else {
            throw new IndexOutOfBoundsException("This collection is empty; You can not remove an element!!\n");
        }
    }

}
