#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

template <typename T>
void PrintVector(const vector<T> &lst)
{
    for (auto i = lst.cbegin(); i != lst.cend(); ++i) 
    {
        cout << *i << " ";
    }
    cout << endl;
}
template <typename T>
void PrintList(const list<T> &lst)
{
    for (auto i = lst.cbegin(); i != lst.cend(); ++i) 
    {
        cout << *i << " ";
    }
    cout << endl;
}

void task1() {
    cout << endl << "Task 1" << endl << endl;
    vector<int> A;
    cout << "Enter range of list : " ;
    int range_A;
    cin >> range_A;
    int number;
    cout << "Enter " << range_A << " numbers : " << endl;
    for (int i = 0; i != range_A; i++) {
		cin >> number;
		A.push_back(number);            //записали числа в список
    }
    cout << "Entered list : " << endl;
    PrintVector(A);

    int cnt = count(A.begin(), A.end(), 3);
    cout << "Number of elements '3' : " << cnt << endl;

    bool srt = is_sorted(A.begin(), A.end());
    if (srt == 1)
        cout << "List is sorted." << endl;
    else
        cout << "List isn't sorted." << endl;

    int max_el = *max_element(A.begin(), A.end());
    cout << "Max element : " << max_el << endl;
    
    int min_el = *min_element(A.begin(), A.end());
    cout << "Min element : " << min_el << endl;
}

void task2() {
    cout << endl << "Task 2" << endl << endl;
    vector<int> B;
    list<int> C;
    for (int i=1; i<=5; i++)
    { 
        B.push_back(i); 
        C.push_back(i+5); 
    }
    cout << "Created vectors : " << endl << endl << "B : ";
    PrintVector(B);
    cout << endl << "C : ";
    PrintList(C);
    cout << endl << endl;

    cout << "Vector B after using 'back_inserter' : " << endl;
    copy(C.begin(),C.end(),back_inserter(B));
    PrintVector(B);

    cout << "Vector C after using 'front_inserter' : " << endl;
    copy(B.begin(),B.end(),front_inserter(C));
    PrintList(C);

    list<int>::iterator it = C.begin();
    advance (it,10);
    cout << "Vector C after using 'inserter' : " << endl;
    copy (B.begin(),B.end(),std::inserter(C,it));
    PrintList(C);
}

void task3() {
    cout << endl << "Task 3" << endl << endl;
	vector<int> D;

	ifstream input("input.txt");
	copy(istream_iterator<int>(input), istream_iterator<int>(), back_inserter(D));
	cout << "Vector D from 'input.txt' : ";
    PrintVector(D);
	cout << endl;
    input.close();

	ofstream output;
	output.open("output.txt");
	copy(D.begin(), D.end(), ostream_iterator<int>(output, " "));
	cout << "Vector D was written to 'output.txt'." << endl;
	output.close();
}

void task4() {
    cout << endl << "Task 4" << endl << endl;
    vector<int> F = { 3, 2, 1 };
	deque<int> E;
    cout << "Vector F : " ;
    PrintVector(F);
    cout << "Deque E is empty now." << endl << endl;
	copy(F.begin(), F.end(), back_inserter(E));
    cout << "Elements was copied." << endl << endl;
	cout << "Deque E after copying elements: ";
	for (auto i = E.begin(); i != E.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

void task5() {
    cout << endl << "Task 5" << endl << endl;
    vector<int> J;
    cout << "Enter range of list : " ;
    int range_J;
    cin >> range_J;
    int number;
    cout << "Enter " << range_J << " numbers : " << endl;
    for (int i = 0; i != range_J; i++) {
		cin >> number;
		J.push_back(number);            //записали числа в список
    }
    cout << "Vector J was created : " ;
    PrintVector(J);
    cout << "Vector J in reverse order: ";
	copy(J.rbegin(), J.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}