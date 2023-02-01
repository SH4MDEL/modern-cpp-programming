#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;


int main()
{
    fastip; sws;

    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);
    vector<int> e(5);

    vector<vector<int>> container;
    container.push_back(e);
    container.push_back(b);
    container.push_back(d);
    container.push_back(a);
    container.push_back(c);

    function<size_t(const vector<int>&)> sz_func = &vector<int>::size;

    vector<int> size_vec(5);
    //transform(container.begin(), container.end(), size_vec.begin(),
    //    sz_func);

    //transform(container.begin(), container.end(), size_vec.begin(),
    //    mem_fn(&vector<int>::size));

    transform(container.begin(), container.end(), size_vec.begin(),
        [](vector<int> v) { return v.size(); });

    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        cout << "º¤ÅÍ Å©±â :: " << *itr << endl;
    }

}