#ifndef HW6_TEST_H
#define HW6_TEST_H
#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include "ArrayList.cpp"
#include "HashSet.cpp"
#include <vector>
#include <list>
#include <typeinfo>
#include <set>

using namespace GTU;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::set;

void testHashSet();
void testArrayList();
void testLinkedList();

template <typename T, typename C1, typename C2, typename C3>
void printCollection(Collection<T, C1> &c1,Collection<T, C2> &c2, Collection<T, C3> &c3);

template <typename T, typename C1, typename C2, typename C3>
void printCollection(Collection<T, C1> &c1,Collection<T, C2> &c2, Collection<T, C3> &c3){

    cout << "implementation with vector" << endl;

    for(int i = 0; i < c1.size(); ++i ){
        cout << c1[i] << " ";
    }

    cout << endl << "implementation with set" << endl;

    for(int i = 0; i < c2.size(); ++i ){
        cout << c2[i] << " " ;
    }

    cout << endl << "implementation with list" << endl;

    for(int i = 0; i < c3.size(); ++i ){
        cout << c3[i] << " ";
    }
	cout << endl;
}
void testHashSet(){
    vector<int> TestVectorInt = {1, 3, 2, 4, 8, 132, 56, 72, 88, 99};
    vector<string> TestVectorStr = {"GTU", "CSE", "241", "OOP", "YSA", "BT", "Saliha", "AA", "Dokuz",  "On"};

    ArrayList<int, vector<int> > AddTestIntv;
    ArrayList<string, vector<string> > AddTestStrv;
    ArrayList<int, set<int> > AddTestInts;
    ArrayList<string, set<string> > AddTestStrs;
    ArrayList<int, list<int> > AddTestIntl;
    ArrayList<string, list<string> > AddTestStrl;

    ArrayList<int, vector<int> > RemTestIntv;
    ArrayList<string, vector<string> > RemTestStrv;
    ArrayList<int, set<int> > RemTestInts;
    ArrayList<string, set<string> > RemTestStrs;
    ArrayList<int, list<int> > RemTestIntl;
    ArrayList<string, list<string> > RemTestStrl;

    ArrayList<int, vector<int> > RetainTestIntv;
    ArrayList<string, vector<string> > RetainTestStrv;
    ArrayList<int, set<int> > RetainTestInts;
    ArrayList<string, set<string> > RetainTestStrs;
    ArrayList<int, list<int> > RetainTestIntl;
    ArrayList<string, list<string> > RetainTestStrl;


    HashSet<int, vector<int> > HashSetTestInt1;
    HashSet<int, set<int> > HashSetTestInt2;
    HashSet<int, list<int> > HashSetTestInt3;
    HashSet<string, vector<string> > HashSetTestStr1;
    HashSet<string, set<string> > HashSetTestStr2;
    HashSet<string, list<string> > HashSetTestStr3;

    AddTestIntv.add(456);
    AddTestStrv.add("456");
    AddTestInts.add(456);
    AddTestStrs.add("456");
    AddTestIntl.add(456);
    AddTestStrl.add("456");

    AddTestIntv.add(46);
    AddTestStrv.add("46");
    AddTestInts.add(46);
    AddTestStrs.add("46");
    AddTestIntl.add(46);
    AddTestStrl.add("46");

    AddTestIntv.add(4569);
    AddTestStrv.add("4569");
    AddTestInts.add(4569);
    AddTestStrs.add("4569");
    AddTestIntl.add(4569);
    AddTestStrl.add("4569");

    RemTestIntv.add(2);
    RemTestStrv.add("Dokuz");
    RemTestInts.add(2);
    RemTestStrs.add("Dokuz");
    RemTestIntl.add(2);
    RemTestStrl.add("Dokuz");
    RemTestIntv.add(8);
    RemTestStrv.add("Saliha");
    RemTestInts.add(8);
    RemTestStrs.add("Saliha");
    RemTestIntl.add(8);
    RemTestStrl.add("Saliha");

    RetainTestIntv.add(88);
    RetainTestStrv.add("241");
    RetainTestInts.add(88);
    RetainTestStrs.add("241");
    RetainTestIntl.add(88);
    RetainTestStrl.add("241");

    RetainTestIntv.add(99);
    RetainTestStrv.add("OOP");
    RetainTestInts.add(99);
    RetainTestStrs.add("OOP");
    RetainTestIntl.add(99);
    RetainTestStrl.add("OOP");

    //Test for Rem function
    for(int i = 0; i < TestVectorInt.size(); ++i){

        HashSetTestInt1.add(TestVectorInt[i]);
        HashSetTestInt2.add(TestVectorInt[i]);
        HashSetTestInt3.add(TestVectorInt[i]);

        HashSetTestStr1.add(TestVectorStr[i]);
        HashSetTestStr2.add(TestVectorStr[i]);
        HashSetTestStr3.add(TestVectorStr[i]);
    }
    //Test for size function, [] overloading and addAll
    cout << "Before addAll" << endl;

    printCollection(HashSetTestInt1, HashSetTestInt2, HashSetTestInt3);
    printCollection(HashSetTestStr1, HashSetTestStr2, HashSetTestStr3);

    HashSetTestInt1.addAll(AddTestIntv);
    HashSetTestInt2.addAll(AddTestInts);
    HashSetTestInt3.addAll(AddTestIntl);

    HashSetTestStr1.addAll(AddTestStrv);
    HashSetTestStr2.addAll(AddTestStrs);
    HashSetTestStr3.addAll(AddTestStrl);

    cout << "After addAll" << endl;

    printCollection(HashSetTestInt1, HashSetTestInt2, HashSetTestInt3);
    printCollection(HashSetTestStr1, HashSetTestStr2, HashSetTestStr3);

    //Remove test
    HashSetTestInt1.remove(3);
    HashSetTestInt2.remove(3);
    HashSetTestInt3.remove(3);

    HashSetTestStr1.remove("CSE");
    HashSetTestStr2.remove("CSE");
    HashSetTestStr3.remove("CSE");

    cout << "After remove" << endl;
    printCollection(HashSetTestInt1, HashSetTestInt2, HashSetTestInt3);
    printCollection(HashSetTestStr1, HashSetTestStr2, HashSetTestStr3);

    //removeAll test
    HashSetTestInt1.removeAll(RemTestIntv);
    HashSetTestInt2.removeAll(RemTestInts);
    HashSetTestInt3.removeAll(RemTestIntl);

    HashSetTestStr1.removeAll(RemTestStrv);
    HashSetTestStr2.removeAll(RemTestStrs);
    HashSetTestStr3.removeAll(RemTestStrl);

    cout << "After removeAll" << endl;
    printCollection(HashSetTestInt1, HashSetTestInt2, HashSetTestInt3);
    printCollection(HashSetTestStr1, HashSetTestStr2, HashSetTestStr3);

    //test for contains and containsAll
    cout << "contains test with int 1" << endl;
    cout << HashSetTestInt1.contains(1) << endl;
    cout << HashSetTestInt2.contains(1) << endl;
    cout << HashSetTestInt3.contains(1) << endl;

    cout << "contains test with string YSA" << endl;
    cout << HashSetTestStr1.contains("YSA") << endl;
    cout << HashSetTestStr2.contains("YSA") << endl;
    cout << HashSetTestStr3.contains("YSA") << endl;

    cout << "containsAll test for int" << endl;
    cout << HashSetTestInt1.containsAll(RemTestIntv) << endl;
    cout << HashSetTestInt2.containsAll(RemTestInts) << endl;
    cout << HashSetTestInt3.containsAll(RemTestIntl) << endl;

    cout << "containsAll test for string" << endl;
    cout << HashSetTestStr1.containsAll(RemTestStrv) << endl;
    cout << HashSetTestStr2.containsAll(RemTestStrs) << endl;
    cout << HashSetTestStr3.containsAll(RemTestStrl) << endl;

    //Test for retainAll
    HashSet<int, vector<int> > HashSetRTestInt1 = HashSetTestInt1.retainAll(RetainTestIntv);
    HashSet<int, set<int> > HashSetRTestInt2 =  HashSetTestInt2.retainAll(RetainTestInts);
    HashSet<int, list<int> > HashSetRTestInt3 = HashSetTestInt3.retainAll(RetainTestIntl);
    HashSet<string, vector<string> > HashSetRTestStr1 = HashSetTestStr1.retainAll(RetainTestStrv);
    HashSet<string, set<string> > HashSetRTestStr2 =  HashSetTestStr2.retainAll(RetainTestStrs);
    HashSet<string, list<string> > HashSetRTestStr3 = HashSetTestStr3.retainAll(RetainTestStrl);

    cout << "retainAll test for int" << endl;
    printCollection(HashSetRTestInt1, HashSetRTestInt2, HashSetRTestInt3);
    cout << "retainAll test for string" << endl;
    printCollection(HashSetRTestStr1, HashSetRTestStr2, HashSetRTestStr3);

    cout << "I've used Iterator class in LinkedList's removeAll " << endl;
    cout << "Only function i haven't used is Iterator::remove() so i will test it here" << endl;

    cout << "Size before iterator remove()" << endl;

    cout << HashSetTestInt1.size() << endl;
    cout << HashSetTestInt2.size() << endl;
    cout << HashSetTestInt3.size() << endl;

    cout << HashSetTestStr1.size() << endl;
    cout << HashSetTestStr2.size() << endl;
    cout << HashSetTestStr3.size() << endl;

    auto i = HashSetTestInt1.iterator();
    i.remove();
    auto j = HashSetTestInt2.iterator();
    j.remove();
    auto k = HashSetTestInt3.iterator();
    k.remove();
    auto l = HashSetTestStr1.iterator();
    l.remove();
    auto m = HashSetTestStr2.iterator();
    m.remove();
    auto n = HashSetTestStr3.iterator();
    n.remove();

    cout << "Size after iterator remove()" << endl;

    cout << HashSetTestInt1.size() << endl;
    cout << HashSetTestInt2.size() << endl;
    cout << HashSetTestInt3.size() << endl;

    cout << HashSetTestStr1.size() << endl;
    cout << HashSetTestStr2.size() << endl;
    cout << HashSetTestStr3.size() << endl;

    cout << "clear and isEmpty functions' test " << endl;

    cout << "isEmpty before clear " << endl;

    cout << HashSetTestInt1.isEmpty() << endl;
    cout << HashSetTestInt2.isEmpty() << endl;
    cout << HashSetTestInt3.isEmpty() << endl;

    cout << HashSetTestStr1.isEmpty() << endl;
    cout << HashSetTestStr2.isEmpty() << endl;
    cout << HashSetTestStr3.isEmpty() << endl;

    HashSetTestInt1.clear();
    HashSetTestInt2.clear();
    HashSetTestInt3.clear();

    HashSetTestStr1.clear();
    HashSetTestStr2.clear();
    HashSetTestStr3.clear();

    cout << "isEmpty after clear " << endl;

    cout << HashSetTestInt1.isEmpty() << endl;
    cout << HashSetTestInt2.isEmpty() << endl;
    cout << HashSetTestInt3.isEmpty() << endl;

    cout << HashSetTestStr1.isEmpty() << endl;
    cout << HashSetTestStr2.isEmpty() << endl;
    cout << HashSetTestStr3.isEmpty() << endl;

    cout << "Exception tests" << endl;
    try{
        HashSetTestInt1.add(1);
        HashSetTestInt1.add(1);
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        HashSetTestInt1.remove(2);
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = HashSetTestInt2.iterator();
        a.elementgetter();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = HashSetTestInt3.iterator();
        a.remove();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = HashSetTestInt3.iterator();
        a.next();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }
}

void testArrayList(){
    vector<int> TestVectorInt = {1, 3, 2, 4, 8, 132, 56, 72, 88, 99};
    vector<string> TestVectorStr = {"GTU", "CSE", "241", "OOP", "YSA", "BT", "Saliha", "AA", "Dokuz",  "On"};

    LinkedList<int, vector<int> > AddTestIntv;
    LinkedList<string, vector<string> > AddTestStrv;
    LinkedList<int, set<int> > AddTestInts;
    LinkedList<string, set<string> > AddTestStrs;
    LinkedList<int, list<int> > AddTestIntl;
    LinkedList<string, list<string> > AddTestStrl;

    LinkedList<int, vector<int> > RemTestIntv;
    LinkedList<string, vector<string> > RemTestStrv;
    LinkedList<int, set<int> > RemTestInts;
    LinkedList<string, set<string> > RemTestStrs;
    LinkedList<int, list<int> > RemTestIntl;
    LinkedList<string, list<string> > RemTestStrl;

    LinkedList<int, vector<int> > RetainTestIntv;
    LinkedList<string, vector<string> > RetainTestStrv;
    LinkedList<int, set<int> > RetainTestInts;
    LinkedList<string, set<string> > RetainTestStrs;
    LinkedList<int, list<int> > RetainTestIntl;
    LinkedList<string, list<string> > RetainTestStrl;


    ArrayList<int, vector<int> > ArrayListInt1;
    ArrayList<int, set<int> > ArrayListInt2;
    ArrayList<int, list<int> > ArrayListInt3;
    ArrayList<string, vector<string> > ArrayListStr1;
    ArrayList<string, set<string> > ArrayListStr2;
    ArrayList<string, list<string> > ArrayListStr3;

    AddTestIntv.add(456);
    AddTestStrv.add("456");
    AddTestInts.add(456);
    AddTestStrs.add("456");
    AddTestIntl.add(456);
    AddTestStrl.add("456");

    AddTestIntv.add(46);
    AddTestStrv.add("46");
    AddTestInts.add(46);
    AddTestStrs.add("46");
    AddTestIntl.add(46);
    AddTestStrl.add("46");

    AddTestIntv.add(4569);
    AddTestStrv.add("4569");
    AddTestInts.add(4569);
    AddTestStrs.add("4569");
    AddTestIntl.add(4569);
    AddTestStrl.add("4569");

    RemTestIntv.add(2);
    RemTestStrv.add("Dokuz");
    RemTestInts.add(2);
    RemTestStrs.add("Dokuz");
    RemTestIntl.add(2);
    RemTestStrl.add("Dokuz");
    RemTestIntv.add(8);
    RemTestStrv.add("Saliha");
    RemTestInts.add(8);
    RemTestStrs.add("Saliha");
    RemTestIntl.add(8);
    RemTestStrl.add("Saliha");

    RetainTestIntv.add(88);
    RetainTestStrv.add("241");
    RetainTestInts.add(88);
    RetainTestStrs.add("241");
    RetainTestIntl.add(88);
    RetainTestStrl.add("241");

    RetainTestIntv.add(99);
    RetainTestStrv.add("OOP");
    RetainTestInts.add(99);
    RetainTestStrs.add("OOP");
    RetainTestIntl.add(99);
    RetainTestStrl.add("OOP");

    //Test for Rem function
    for(int i = 0; i < TestVectorInt.size(); ++i){

        ArrayListInt1.add(TestVectorInt[i]);
        ArrayListInt2.add(TestVectorInt[i]);
        ArrayListInt3.add(TestVectorInt[i]);

        ArrayListStr1.add(TestVectorStr[i]);
        ArrayListStr2.add(TestVectorStr[i]);
        ArrayListStr3.add(TestVectorStr[i]);
    }
    //Test for size function, [] overloading and addAll
    cout << "Before addAll" << endl;

    printCollection(ArrayListInt1, ArrayListInt2, ArrayListInt3);
    printCollection(ArrayListStr1, ArrayListStr2, ArrayListStr3);

    ArrayListInt1.addAll(AddTestIntv);
    ArrayListInt2.addAll(AddTestInts);
    ArrayListInt3.addAll(AddTestIntl);

    ArrayListStr1.addAll(AddTestStrv);
    ArrayListStr2.addAll(AddTestStrs);
    ArrayListStr3.addAll(AddTestStrl);

    cout << "After addAll" << endl;

    printCollection(ArrayListInt1, ArrayListInt2, ArrayListInt3);
    printCollection(ArrayListStr1, ArrayListStr2, ArrayListStr3);

    //Remove test
    ArrayListInt1.remove(3);
    ArrayListInt2.remove(3);
    ArrayListInt3.remove(3);

    ArrayListStr1.remove("CSE");
    ArrayListStr2.remove("CSE");
    ArrayListStr3.remove("CSE");

    cout << "After remove" << endl;
    printCollection(ArrayListInt1, ArrayListInt2, ArrayListInt3);
    printCollection(ArrayListStr1, ArrayListStr2, ArrayListStr3);

    //removeAll test
    ArrayListInt1.removeAll(RemTestIntv);
    ArrayListInt2.removeAll(RemTestInts);
    ArrayListInt3.removeAll(RemTestIntl);

    ArrayListStr1.removeAll(RemTestStrv);
    ArrayListStr2.removeAll(RemTestStrs);
    ArrayListStr3.removeAll(RemTestStrl);

    cout << "After removeAll" << endl;
    printCollection(ArrayListInt1, ArrayListInt2, ArrayListInt3);
    printCollection(ArrayListStr1, ArrayListStr2, ArrayListStr3);

    //test for contains and containsAll
    cout << "contains test with int 1" << endl;
    cout << ArrayListInt1.contains(1) << endl;
    cout << ArrayListInt2.contains(1) << endl;
    cout << ArrayListInt3.contains(1) << endl;

    cout << "contains test with string YSA" << endl;
    cout << ArrayListStr1.contains("YSA") << endl;
    cout << ArrayListStr2.contains("YSA") << endl;
    cout << ArrayListStr3.contains("YSA") << endl;

    cout << "containsAll test for int" << endl;
    cout << ArrayListInt1.containsAll(RemTestIntv) << endl;
    cout << ArrayListInt2.containsAll(RemTestInts) << endl;
    cout << ArrayListInt3.containsAll(RemTestIntl) << endl;

    cout << "containsAll test for string" << endl;
    cout << ArrayListStr1.containsAll(RemTestStrv) << endl;
    cout << ArrayListStr2.containsAll(RemTestStrs) << endl;
    cout << ArrayListStr3.containsAll(RemTestStrl) << endl;

    //Test for retainAll
    ArrayList<int, vector<int> > ArrayListRTestInt1 = ArrayListInt1.retainAll(RetainTestIntv);
    ArrayList<int, set<int> > ArrayListRTestInt2 =  ArrayListInt2.retainAll(RetainTestInts);
    ArrayList<int, list<int> > ArrayListRTestInt3 = ArrayListInt3.retainAll(RetainTestIntl);
    ArrayList<string, vector<string> > ArrayListRTestStr1 = ArrayListStr1.retainAll(RetainTestStrv);
    ArrayList<string, set<string> > ArrayListRTestStr2 =  ArrayListStr2.retainAll(RetainTestStrs);
    ArrayList<string, list<string> > ArrayListRTestStr3 = ArrayListStr3.retainAll(RetainTestStrl);

    cout << "retainAll test for int" << endl;
    printCollection(ArrayListRTestInt1, ArrayListRTestInt2, ArrayListRTestInt3);
    cout << "retainAll test for string" << endl;
    printCollection(ArrayListRTestStr1, ArrayListRTestStr2, ArrayListRTestStr3);

    cout << "I've used Iterator class in LinkedList's removeAll " << endl;
    cout << "Only function i haven't used is Iterator::remove() so i will test it here" << endl;

    cout << "Size before iterator remove()" << endl;

    cout << ArrayListInt1.size() << endl;
    cout << ArrayListInt2.size() << endl;
    cout << ArrayListInt3.size() << endl;

    cout << ArrayListStr1.size() << endl;
    cout << ArrayListStr2.size() << endl;
    cout << ArrayListStr3.size() << endl;

    auto i = ArrayListInt1.iterator();
    i.remove();
    auto j = ArrayListInt2.iterator();
    j.remove();
    auto k = ArrayListInt3.iterator();
    k.remove();
    auto l = ArrayListStr1.iterator();
    l.remove();
    auto m = ArrayListStr2.iterator();
    m.remove();
    auto n = ArrayListStr3.iterator();
    n.remove();

    cout << "Size after iterator remove()" << endl;

    cout << ArrayListInt1.size() << endl;
    cout << ArrayListInt2.size() << endl;
    cout << ArrayListInt3.size() << endl;

    cout << ArrayListStr1.size() << endl;
    cout << ArrayListStr2.size() << endl;
    cout << ArrayListStr3.size() << endl;

    cout << "clear and isEmpty functions' test " << endl;

    cout << "isEmpty before clear " << endl;

    cout << ArrayListInt1.isEmpty() << endl;
    cout << ArrayListInt2.isEmpty() << endl;
    cout << ArrayListInt3.isEmpty() << endl;

    cout << ArrayListStr1.isEmpty() << endl;
    cout << ArrayListStr2.isEmpty() << endl;
    cout << ArrayListStr3.isEmpty() << endl;

    ArrayListInt1.clear();
    ArrayListInt2.clear();
    ArrayListInt3.clear();

    ArrayListStr1.clear();
    ArrayListStr2.clear();
    ArrayListStr3.clear();

    cout << "isEmpty after clear " << endl;

    cout << ArrayListInt1.isEmpty() << endl;
    cout << ArrayListInt2.isEmpty() << endl;
    cout << ArrayListInt3.isEmpty() << endl;

    cout << ArrayListStr1.isEmpty() << endl;
    cout << ArrayListStr2.isEmpty() << endl;
    cout << ArrayListStr3.isEmpty() << endl;

    cout << "Exception tests" << endl;

    try{
        ArrayListInt1.remove(2);
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = ArrayListInt2.iterator();
        a.elementgetter();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = ArrayListInt3.iterator();
        a.remove();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = ArrayListInt3.iterator();
        a.next();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }
}

void testLinkedList(){
    vector<int> TestVectorInt = {1, 2, 3, 4, 8, 132, 56, 72, 88, 99};
    vector<string> TestVectorStr = {"241", "AA", "BT", "GTU", "CSE",  "OOP", "YSA", "Saliha",  "Dokuz",  "On"};

    ArrayList<int, vector<int> > AddTestIntv;
    ArrayList<string, vector<string> > AddTestStrv;
    ArrayList<int, set<int> > AddTestInts;
    ArrayList<string, set<string> > AddTestStrs;
    ArrayList<int, list<int> > AddTestIntl;
    ArrayList<string, list<string> > AddTestStrl;

    ArrayList<int, vector<int> > RemTestIntv;
    ArrayList<string, vector<string> > RemTestStrv;
    ArrayList<int, set<int> > RemTestInts;
    ArrayList<string, set<string> > RemTestStrs;
    ArrayList<int, list<int> > RemTestIntl;
    ArrayList<string, list<string> > RemTestStrl;

    ArrayList<int, vector<int> > RetainTestIntv;
    ArrayList<string, vector<string> > RetainTestStrv;
    ArrayList<int, set<int> > RetainTestInts;
    ArrayList<string, set<string> > RetainTestStrs;
    ArrayList<int, list<int> > RetainTestIntl;
    ArrayList<string, list<string> > RetainTestStrl;


    LinkedList<int, vector<int> > LinkedListTestInt1;
    LinkedList<int, set<int> > LinkedListTestInt2;
    LinkedList<int, list<int> > LinkedListTestInt3;
    LinkedList<string, vector<string> > LinkedListTestStr1;
    LinkedList<string, set<string> > LinkedListTestStr2;
    LinkedList<string, list<string> > LinkedListTestStr3;

    AddTestIntv.add(456);
    AddTestStrv.add("456");
    AddTestInts.add(456);
    AddTestStrs.add("456");
    AddTestIntl.add(456);
    AddTestStrl.add("456");

    AddTestIntv.add(46);
    AddTestStrv.add("46");
    AddTestInts.add(46);
    AddTestStrs.add("46");
    AddTestIntl.add(46);
    AddTestStrl.add("46");

    AddTestIntv.add(4569);
    AddTestStrv.add("4569");
    AddTestInts.add(4569);
    AddTestStrs.add("4569");
    AddTestIntl.add(4569);
    AddTestStrl.add("4569");

    RemTestIntv.add(2);
    RemTestStrv.add("AA");
    RemTestInts.add(2);
    RemTestStrs.add("AA");
    RemTestIntl.add(2);
    RemTestStrl.add("AA");
    RemTestIntv.add(3);
    RemTestStrv.add("BT");
    RemTestInts.add(3);
    RemTestStrs.add("BT");
    RemTestIntl.add(3);
    RemTestStrl.add("BT");

    RetainTestIntv.add(88);
    RetainTestStrv.add("YSA");
    RetainTestInts.add(88);
    RetainTestStrs.add("YSA");
    RetainTestIntl.add(88);
    RetainTestStrl.add("YSA");

    RetainTestIntv.add(99);
    RetainTestStrv.add("OOP");
    RetainTestInts.add(99);
    RetainTestStrs.add("OOP");
    RetainTestIntl.add(99);
    RetainTestStrl.add("OOP");

    //Test for add function
    for(int i = 0; i < TestVectorInt.size(); ++i){

        LinkedListTestInt1.add(TestVectorInt[i]);
        LinkedListTestInt2.add(TestVectorInt[i]);
        LinkedListTestInt3.add(TestVectorInt[i]);

        LinkedListTestStr1.add(TestVectorStr[i]);
        LinkedListTestStr2.add(TestVectorStr[i]);
        LinkedListTestStr3.add(TestVectorStr[i]);
    }

    cout << "Test for element() that returns head of LinkedList " << endl;
    auto q = LinkedListTestInt1.element();
    auto w = LinkedListTestInt2.element();
    auto e = LinkedListTestInt3.element();

    auto a = LinkedListTestStr1.element();
    auto s = LinkedListTestStr2.element();
    auto d = LinkedListTestStr3.element();

    cout << q << " " << w << " " << e << " " << a << " " << s << " " << d << endl;

    //Test for size function, [] overloading and addAll
    cout << "Before remove" << endl;

    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    //Remove test
    LinkedListTestInt1.remove(1);
    LinkedListTestInt2.remove(1);
    LinkedListTestInt3.remove(1);

    LinkedListTestStr1.remove("241");
    LinkedListTestStr2.remove("241");
    LinkedListTestStr3.remove("241");

    cout << "After remove" << endl;
    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    //removeAll test
    LinkedListTestInt1.removeAll(RemTestIntv);
    LinkedListTestInt2.removeAll(RemTestInts);
    LinkedListTestInt3.removeAll(RemTestIntl);

    LinkedListTestStr1.removeAll(RemTestStrv);
    LinkedListTestStr2.removeAll(RemTestStrs);
    LinkedListTestStr3.removeAll(RemTestStrl);

    cout << "After removeAll" << endl;
    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    LinkedListTestInt1.addAll(AddTestIntv);
    LinkedListTestInt2.addAll(AddTestInts);
    LinkedListTestInt3.addAll(AddTestIntl);

    LinkedListTestStr1.addAll(AddTestStrv);
    LinkedListTestStr2.addAll(AddTestStrs);
    LinkedListTestStr3.addAll(AddTestStrl);

    cout << "After addAll" << endl;

    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    //offer test
    cout << "After offer" << endl;

    LinkedListTestInt1.add(23);
    LinkedListTestInt2.add(23);
    LinkedListTestInt3.add(23);

    LinkedListTestStr1.add("23");
    LinkedListTestStr2.add("23");
    LinkedListTestStr3.add("23");

    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    //poll test
    cout << "After poll" << endl;

    LinkedListTestInt1.poll();
    LinkedListTestInt2.poll();
    LinkedListTestInt3.poll();

    LinkedListTestStr1.poll();
    LinkedListTestStr2.poll();
    LinkedListTestStr3.poll();

    printCollection(LinkedListTestInt1, LinkedListTestInt2, LinkedListTestInt3);
    printCollection(LinkedListTestStr1, LinkedListTestStr2, LinkedListTestStr3);

    //test for contains and containsAll
    cout << "contains test with int 88" << endl;
    cout << LinkedListTestInt1.contains(88) << endl;
    cout << LinkedListTestInt2.contains(88) << endl;
    cout << LinkedListTestInt3.contains(88) << endl;

    cout << "contains test with string YSA" << endl;
    cout << LinkedListTestStr1.contains("YSA") << endl;
    cout << LinkedListTestStr2.contains("YSA") << endl;
    cout << LinkedListTestStr3.contains("YSA") << endl;

    cout << "containsAll test for int" << endl;
    cout << LinkedListTestInt1.containsAll(RemTestIntv) << endl;
    cout << LinkedListTestInt2.containsAll(RemTestInts) << endl;
    cout << LinkedListTestInt3.containsAll(RemTestIntl) << endl;

    cout << "containsAll test for string" << endl;
    cout << LinkedListTestStr1.containsAll(RemTestStrv) << endl;
    cout << LinkedListTestStr2.containsAll(RemTestStrs) << endl;
    cout << LinkedListTestStr3.containsAll(RemTestStrl) << endl;

    //Test for retainAll
    LinkedList<int, vector<int> > LinkedListRTestInt1 = LinkedListTestInt1.retainAll(RetainTestIntv);
    LinkedList<int, set<int> > LinkedListRTestInt2 =  LinkedListTestInt2.retainAll(RetainTestInts);
    LinkedList<int, list<int> > LinkedListRTestInt3 = LinkedListTestInt3.retainAll(RetainTestIntl);
    LinkedList<string, vector<string> > LinkedListRTestStr1 = LinkedListTestStr1.retainAll(RetainTestStrv);
    LinkedList<string, set<string> > LinkedListRTestStr2 =  LinkedListTestStr2.retainAll(RetainTestStrs);
    LinkedList<string, list<string> > LinkedListRTestStr3 = LinkedListTestStr3.retainAll(RetainTestStrl);

    cout << "retainAll test for int" << endl;
    printCollection(LinkedListRTestInt1, LinkedListRTestInt2, LinkedListRTestInt3);
    cout << "retainAll test for string" << endl;
    printCollection(LinkedListRTestStr1, LinkedListRTestStr2, LinkedListRTestStr3);

    cout << "I've used Iterator class in LinkedList's removeAll " << endl;
    cout << "Only function i haven't used is Iterator::remove() so i will test it here" << endl;

    cout << "Size before iterator remove()" << endl;

    cout << LinkedListTestInt1.size() << endl;
    cout << LinkedListTestInt2.size() << endl;
    cout << LinkedListTestInt3.size() << endl;

    cout << LinkedListTestStr1.size() << endl;
    cout << LinkedListTestStr2.size() << endl;
    cout << LinkedListTestStr3.size() << endl;

    auto i = LinkedListTestInt1.iterator();
    i.remove();
    auto j = LinkedListTestInt2.iterator();
    j.remove();
    auto k = LinkedListTestInt3.iterator();
    k.remove();
    auto l = LinkedListTestStr1.iterator();
    l.remove();
    auto m = LinkedListTestStr2.iterator();
    m.remove();
    auto n = LinkedListTestStr3.iterator();
    n.remove();

    cout << "Size after iterator remove()" << endl;

    cout << LinkedListTestInt1.size() << endl;
    cout << LinkedListTestInt2.size() << endl;
    cout << LinkedListTestInt3.size() << endl;

    cout << LinkedListTestStr1.size() << endl;
    cout << LinkedListTestStr2.size() << endl;
    cout << LinkedListTestStr3.size() << endl;

    cout << "clear and isEmpty functions' test " << endl;

    cout << "isEmpty before clear " << endl;

    cout << LinkedListTestInt1.isEmpty() << endl;
    cout << LinkedListTestInt2.isEmpty() << endl;
    cout << LinkedListTestInt3.isEmpty() << endl;

    cout << LinkedListTestStr1.isEmpty() << endl;
    cout << LinkedListTestStr2.isEmpty() << endl;
    cout << LinkedListTestStr3.isEmpty() << endl;

    LinkedListTestInt1.clear();
    LinkedListTestInt2.clear();
    LinkedListTestInt3.clear();

    LinkedListTestStr1.clear();
    LinkedListTestStr2.clear();
    LinkedListTestStr3.clear();

    cout << "isEmpty after clear " << endl;

    cout << LinkedListTestInt1.isEmpty() << endl;
    cout << LinkedListTestInt2.isEmpty() << endl;
    cout << LinkedListTestInt3.isEmpty() << endl;

    cout << LinkedListTestStr1.isEmpty() << endl;
    cout << LinkedListTestStr2.isEmpty() << endl;
    cout << LinkedListTestStr3.isEmpty() << endl;

    cout << "Exception tests" << endl;

    try{
        LinkedListTestInt1.remove(2);
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        LinkedList<int , vector<int> > notHeadRtest(TestVectorInt);
        notHeadRtest.remove(2);

    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        LinkedListTestInt3.poll();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = LinkedListTestInt2.iterator();
        a.elementgetter();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = LinkedListTestInt3.iterator();
        a.remove();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

    try{
        auto a = LinkedListTestInt3.iterator();
        a.next();
    }
    catch (std::exception & e){
        std::cerr << e.what() << endl;
    }

}
#endif //HW6_TEST_H
