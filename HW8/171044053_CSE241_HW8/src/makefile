JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	ArrayList.java \
	LinkedList.java \
	List.java \
	Set.java \
	Queue.java \
	Iterator.java \
	HashSet.java \
	Collection.java \
	Main_171044053.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
