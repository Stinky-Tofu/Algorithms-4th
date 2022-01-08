//
//  IndexMinPQ.cpp
//  Algorithms-4th
//
//  Created by Stinky Tofu on 2022/1/8.
//

#include "IndexMinPQ.hpp"

template<class Key>
inline IndexMinPQ<Key>::IndexMinPQ(int maxN)
{
    if (maxN < 0) {
        std::cout << "maxN needs >0.\n";
        return;
    }

    m_maxN = maxN;
    m_N = 0;//队列中元素个数
    m_keys = new vector<Key>(maxN + 1);
    m_pq = new vector<int>(maxN + 1);
    m_qp = new vector<int>(maxN + 1);

    //不要0位置
    for (int i = 1; i <= maxN; ++i)
    {
        m_qp->at(i) = -1;
    }

}

template<class Key>
void IndexMinPQ<Key>::insert(int i, Key key)
{
    if (contains(i)) {
        std::cout << "index is already in the priority queue." << std::endl;
        return;
    }

    m_N++;
    //加到末尾，并上浮
    m_qp->at(i) = m_N;
    m_pq->at(m_N) = i;
    m_keys->at(i) = key;
    swim(m_N);
}

template<class Key>
Key IndexMinPQ<Key>::min()
{
    int min_i = m_pq->at(1);
    return m_keys->at(min_i);
}

template<class Key>
int IndexMinPQ<Key>::delMin()
{
    if (m_N == 0) {
        std::cout << "priority queue underflow." << std::endl;
        return -1;
    }
    int min = m_pq->at(1);
    exch(1, m_N--);
    sink(1);
    //assert(min == m_pq[m_N + 1]);

    m_qp->at(min) = -1;
    m_keys->at(min) = Key();
    m_pq->at(m_N + 1) = -1;
    return min;
}

template<class Key>
void IndexMinPQ<Key>::change(int i, Key key)
{
    validateIndex(i);
    if (!contains(i)) {
        std::cout << "index is not in priority queue." << std::endl;
        return;
    }
    m_keys->at(i) = key;
    swim(m_qp->at(i));
    sink(m_qp->at(i));
}

template<class Key>
void IndexMinPQ<Key>::sink(int k)
{
    while (k * 2 <= m_N) {
        int j = 2 * k;
        if (j < m_N && less(j, j + 1)) j++;
        if (!less(k, j)) break;
        exch(k, j);
        k = j;
    }
}

template<class Key>
void IndexMinPQ<Key>::swim(int k)
{
    while (k > 1 && less(k / 2, k)) {
        exch(k, k / 2);
        k = k / 2;
    }
}

template<class Key>
void IndexMinPQ<Key>::exch(int x, int y)
{
    Key swap_ = m_pq->at(x);
    m_pq->at(x) = m_pq->at(y);
    m_pq->at(y) = swap_;

    //调整完后，更新qp
    m_qp->at(m_pq->at(x)) = x;
    m_qp->at(m_pq->at(y)) = y;
}

template<class Key>
bool IndexMinPQ<Key>::greater(int i, int j)
{//优先队列存索引
    i = m_pq->at(i);
    j = m_pq->at(j);
    return m_keys->at(i) < m_keys->at(j);
}

template<class Key>
bool IndexMinPQ<Key>::less(int x, int y)
{
    x = m_pq->at(x);
    y = m_pq->at(y);
    return m_keys->at(x) > m_keys->at(y);
}

template<class Key>
void IndexMinPQ<Key>::validateIndex(int idx)
{
    if (idx<1 || idx>m_maxN) {
        std::cout << "index error!\n" << std::endl;
    }
}

void test_IndexMinPQ() {
    double a[4] = {3.17,10.5,4.67,9.09};
    IndexMinPQ<double> minPQ(9);
    for (int i = 0; i < 4; ++i) {
        minPQ.insert(i + 1, a[i]);
    }

    std::cout << minPQ.min() << std::endl;
    minPQ.change(3, 2.09);
    std::cout << minPQ.min() << std::endl;
    minPQ.change(4, 1.89);
    std::cout << minPQ.min() << std::endl;
    
}
