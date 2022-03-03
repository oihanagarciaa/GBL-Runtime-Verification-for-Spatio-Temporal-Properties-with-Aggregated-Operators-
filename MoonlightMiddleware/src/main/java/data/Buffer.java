package data;


import java.util.Collection;

/**
 * This buffer abstracts the interaction with the data from the application.
 */
public interface Buffer<E> {

    /**
     * Primitive for adding an element to the buffer
     * @param element element to be stored
     * @return <code>true</code> if the buffer gets full
     */
    boolean add(E element);

    /**
     * Primitive for retrieving the current data of the buffer
     * @return the collection of elements stored in the buffer
     */
    Collection<E> get();

    /**
     * Primitive for emptying the buffer
     */
    void flush();
}
