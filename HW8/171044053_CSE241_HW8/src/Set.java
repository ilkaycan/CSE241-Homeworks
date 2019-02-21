/**
 * A collection that contains no duplicate elements. 
 * There is no order for this collection. In other words, 
 * you don’t have to keep the insertion order of the elements.
 * Set is generic
 * @author İlkay CAN - 171044053
 *
 * @param <E> defines type of data
 */
public interface Set<E> extends Collection<E> {
	public abstract Iterator <E> iterator();
	public abstract boolean add (E e);
	public abstract boolean addAll(Collection<E> c); 
	public abstract void clear();
	public abstract boolean contains(E e); 
	public abstract boolean containsAll(Collection<E> c); 
	public abstract boolean isEmpty();
	public abstract boolean remove(E e); 
	public abstract boolean removeAll(Collection<E> c); 
	public abstract Collection<E> retainAll( Collection<E> c);
	public abstract int size(); 
	public abstract E element();
	public abstract boolean offer(E e);
	public abstract E poll();
}
