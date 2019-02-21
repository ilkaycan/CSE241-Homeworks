/**
 * Queues order elements in a FIFO (first-in-first-out) manner. 
 * There is no random access with this Collection. Some functions throw exceptions.
 * Set is generic
 * @author 1710444053
 *
 * @param <E> defines type of data
 */

public interface Queue<E> extends Collection<E>{
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
