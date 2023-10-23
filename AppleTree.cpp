#include <iostream>

#include <string>

using namespace std;


class AppleTree {
public:
    AppleTree(string Name, int init_num_apples){
        num_apples_in_tree = init_num_apples;
        name = Name;
    }
    void harvest_one() {
        num_apples_in_tree -= 1;
    }
    int apples_in_tree() {
        return num_apples_in_tree;
    }
    string tree_name() {
        return name;
    }
private:
    int num_apples_in_tree;
    string name;
};


class Person;

class Basket {
public:
    Basket(int init_cap_basket, int init_apples_in_basket, Person &worker); /*{
        cap_basket = init_cap_basket;
        num_apples_in_basket = init_apples_in_basket;
        owner = worker.get_name();
    }*/
    void add_one_apple() {
        num_apples_in_basket += 1;
    }
    int apples_in_basket() {
        return num_apples_in_basket;
    }
    string basket_owner() {
        return owner;
    }
    void empty_basket() {
        num_apples_in_basket = 0;
    }
private:
    int cap_basket;
    int num_apples_in_basket;
    string owner;
};

class Wagon {
public:
    Wagon(int init_cap_wagon, int init_apples_in_wagon, Person &worker); /* {
        cap_wagon = init_cap_wagon;
        num_apples_in_wagon = init_apples_in_wagon;
        owner = worker.get_name();
    }*/
    int apples_in_wagon() {
        return num_apples_in_wagon;
    }
    string wagon_owner() {
        return owner;
    }

    void empty_wagon() {
        num_apples_in_wagon = 0;
    }
    void add_apples(int num) {
        num_apples_in_wagon += num;
    }
private:
    int cap_wagon;
    int num_apples_in_wagon;
    string owner;
};


class Storage {
public:
    Storage(int init_cap_storage, int init_num_apples_in_storage, Person &worker); /* {
        cap_storage = init_cap_storage;
        num_apples_in_storage = init_num_apples_in_storage;
        owner = worker.get_name();
    }*/
    string storage_owner() {
        return owner;
    }
    void add_apples(int num) {
        num_apples_in_storage += num;
    }
    int apples_in_storage() {
        return num_apples_in_storage;
    }
private:
    int cap_storage;
    int num_apples_in_storage;
    string owner;
};

 




class Person {
public:
    Person(string Name, string Gender, int Age){
        name = Name;
        gender = Gender;
        age = Age;
    }

    string get_name() {
        return name;
    }
    
    void pick_apple(AppleTree &tree) {
        cout << "pick an apple" << endl;
        tree.harvest_one();
        cout << "num apples in " << tree.tree_name() << " after picking apple: " << tree.apples_in_tree() << endl;
    }

    void put_into_basket(Basket &basket) {
        cout << "put into basket" << endl;
        basket.add_one_apple();
        cout << "num apples in basket of " << basket.basket_owner() << " after putting into basket: " << basket.apples_in_basket() << endl;
    }

    void empty_basket(Basket &basket) {
        cout << "empty basket" << endl;
        basket.empty_basket();
        cout << "num apples in basket of " << basket.basket_owner() << " after emptying basket: " << basket.apples_in_basket() << endl;
    }

    void load_into_wagon(Basket &basket, Wagon &wagon) {
        cout << "load into wagon" << endl;
        wagon.add_apples(basket.apples_in_basket());
        cout << "num apples in wagon of " << wagon.wagon_owner() << " after loading into wagon: " << wagon.apples_in_wagon() << endl;
    }

    void empty_wagon(Wagon &wagon) {
        wagon.empty_wagon();
        cout << "num apples in wagon of " << wagon.wagon_owner() << " after emptying wagon: " << wagon.apples_in_wagon() << endl;
    }

    void store_in_storage(Wagon &wagon, Storage &storage) {
        cout << "store in storage" << endl;
        storage.add_apples(wagon.apples_in_wagon());
        cout << "num apples in storage of " << storage.storage_owner() << " after storing in storage: " << storage.apples_in_storage() << endl;
    }
    

private:
    string name;
    string gender;
    int age;
};

Basket::Basket(int init_cap_basket, int init_apples_in_basket, Person &worker){
        cap_basket = init_cap_basket;
        num_apples_in_basket = init_apples_in_basket;
        owner = worker.get_name();
}


Wagon::Wagon(int init_cap_wagon, int init_apples_in_wagon, Person &worker){
        cap_wagon = init_cap_wagon;
        num_apples_in_wagon = init_apples_in_wagon;
        owner = worker.get_name();
}


Storage::Storage(int init_cap_storage, int init_num_apples_in_storage, Person &worker){
        cap_storage = init_cap_storage;
        num_apples_in_storage = init_num_apples_in_storage;
        owner = worker.get_name();
}



int main() {
    AppleTree tree1 = AppleTree("apple_tree_1", 100);
    Person worker1 = Person("Nnamdi", "male", 22);
    Basket basket1 = Basket(5, 0, worker1);
    Wagon wagon1 = Wagon(40, 0, worker1);
    Storage storage1 = Storage(500, 0, worker1);

    cout << wagon1.wagon_owner() << endl;








    /*

    cout << "\n\n================= Number of Apples in Objects ==============\n";
    cout << "num apples in tree1 = " << tree1.apples_in_tree();
    cout << "num apples in basket1 = " << basket1.apples_in_basket();
    cout << "num apples in wagon1 = " << wagon1.apples_in_wagon();
    cout << "num apples in storage1 = " << storage1.apples_in_storage();
    cout << "\n==============================================================\n";
    




    
    
    for time in range(0, 150, 1) {
        print("==== time ", time, " =====")
            //task for worker1(John)
            if (basket1.num_apples_in_basket < basket1.cap_basket) { //if basket is not full
                if (tree1.num_apples_in_tree > 0) { //if tree has apple to be picked
                    worker1.pick_apple(tree1);
                    worker1.put_into_basket(basket1);
                }
                else { //if tree doesn't have apple to be picked
                    print("\n\n=========== No apples in the tree ==============");
                    print("\n====== time = ", time, "(stopped) ================");
                    print_num_apples_in_objects();
                    break;
                }//if tree doesn't have apple, stop working
            }
            else if (basket1.cap_basket <= wagon1.cap_wagon - wagon1.num_apples_in_wagon) { //if wagon is not full
                worker1.load_into_wagon(basket1, wagon1);
                worker1.empty_basket(basket1);
            }
            else {
                cout << ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&") << endl;
                print_num_apples_in_objects();
            }
        //task for worker2(Rachel)
        if (wagon1.cap_wagon <= wagon1.num_apples_in_wagon) { //if wagon is full
            worker2.store_in_storage(wagon1, storage1);
            worker2.empty_wagon(wagon1);
        }
    }
    */
    
    return 0;
}