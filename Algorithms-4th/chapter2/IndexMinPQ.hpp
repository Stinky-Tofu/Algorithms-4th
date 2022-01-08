//
//  IndexMinPQ.hpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#ifndef IndexMinPQ_hpp
#define IndexMinPQ_hpp

#include<string>
#include<iostream>
#include<vector>
using namespace std;

template<class Key>
class IndexMinPQ
{
public:
    IndexMinPQ(int maxN);

    //functions
    bool empty() { return m_N == 0; }
    int size() { return m_N; }
    bool contains(int k) { return (*m_qp)[k] != -1; }
    int minIndex() { return m_pq[1]; }
    Key keyOf(int k) { return m_keys->at(k); }


    Key min();
    int delMin();
    void change(int k, Key key);
    void insert(int i, Key key);
    void remove(int k);
private:
    int m_maxN = 0;
    int m_N = 0;
    vector<int>* m_pq = nullptr;//保存索引，二叉堆，从一开始
    vector<int>* m_qp = nullptr;//逆序，qp[pq[i]]=pq[qp[i]]=i
    vector<Key>* m_keys = nullptr;//保存元素

    void sink(int k);//下沉
    void swim(int k);//上浮
    bool less(int x, int y);//y是否小于x
    void exch(int x, int y);
    bool greater(int i, int j);//x是否大于y

    void validateIndex(int idx);
};

void test_IndexMinPQ();

#endif /* IndexMinPQ_hpp */
