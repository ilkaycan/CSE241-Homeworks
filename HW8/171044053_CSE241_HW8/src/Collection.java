/**
 * This is a generic class with one generic parameters which is the generic type E.
 * @author Ilkay CAN - 171044053
 *
 * @param <E> defines type of data
 */

public interface Collection<E> {
	/**
	 * This function creates an Iterator for collection
	 * @return Iterator 
	 */
	public abstract Iterator <E> iterator();
	
	/**
	 * This function adds given value to collection
	 * @param e
	 * @return true if add is succesfull
	 */
	public abstract boolean add (E e);
	/**
	 * This function adds given collection to the this
	 * @param c
	 * @return true if add is succesfull
	 */
	public abstract boolean addAll(Collection<E> c); 
	/**
	 * Makes collection empty
	 */
	public abstract void clear();
	/**
	 * Checks if given element exists in collection
	 * @param e
	 * @return true if element exists in collection
	 */
	public abstract boolean contains(E e); 
	/**
	 * Checks if given collection exists in collection
	 * @param c
	 * @return true if element exists in collection
	 */
	public abstract boolean containsAll(Collection<E> c); 
	/**
	 * Checks if given collection is empty
	 * @return true if collection is empty
	 */
	public abstract boolean isEmpty();
	/**
	 * removes given element 
	 * @param e
	 * @return true if remove is succesfull
	 */
	public abstract boolean remove(E e); 
	/**
	 * removes given collection 
	 * @param c
	 * @return true if remove is succesfull
	 */
	public abstract boolean removeAll(Collection<E> c); 
	/**
	 * Checks Intersection
	 * @param c
	 * @return Intersection 
	 */
	public abstract Collection<E> retainAll( Collection<E> c);
	/**
	 * Calculates size
	 * @return size
	 */
	public abstract int size();
	
	/**
	 * 
	 * @return element in first index
	 */
	public abstract E element();
	/**
	 * adds given element to the collection
	 * @param e
	 * @return true if offer is succesfull
	 */
	public abstract boolean offer(E e);
	/**
	 * removes last element
	 * @return last element
	 */
	public abstract E poll(); 
	/**
	 * 
	 * @param index
	 * @return returns element in given index
	 */
	public abstract E at(int index);

    }

