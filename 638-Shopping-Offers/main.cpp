#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // upper limit of item types
    static const int K = 6;
    static const int INF = 0x7fffffff;

    static int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        // optimal payment matrix
        vector<vector<vector<vector<vector<vector<int>>>>>> P;

        price.resize(K, 0);
        needs.resize(K, 0);

        P.resize(1 + needs[0]);
        for (auto &a:P) {
            a.resize(1 + needs[1]);
            for (auto &b:a) {
                b.resize(1 + needs[2]);
                for (auto &c:b) {
                    c.resize(1 + needs[3]);
                    for (auto &d:c) {
                        d.resize(1 + needs[4]);
                        for (auto &e:d) {
                            e.resize(1 + needs[5]);
                        }
                    }
                }
            }
        }

        vector<int> offer(6);
        int offset;
        int *ptr;
        for (int a = 0; a <= needs[0]; ++a) {
            for (int b = 0; b <= needs[1]; ++b) {
                for (int c = 0; c <= needs[2]; ++c) {
                    for (int d = 0; d <= needs[3]; ++d) {
                        for (int e = 0; e <= needs[4]; ++e) {
                            for (int f = 0; f <= needs[5]; ++f) {
                                ptr = &P[a][b][c][d][e][f];
                                if ((0 == a) && (0 == b) && (0 == c) && (0 == d) && (0 == e) && (0 == f)) {
                                    *ptr = 0;
                                    continue;
                                }

                                *ptr = INF;
                                // reset offer vector
                                for (auto &ofr:offer) {
                                    ofr = 0;
                                }
                                // for single item
                                offset = -1;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a - 1][b][c][d][e][f])) {
                                    *ptr = price[offset] + P[a - 1][b][c][d][e][f];
                                }

                                offer[offset] = 0;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a][b - 1][c][d][e][f])) {
                                    *ptr = price[offset] + P[a][b - 1][c][d][e][f];
                                }

                                offer[offset] = 0;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a][b][c - 1][d][e][f])) {
                                    *ptr = price[offset] + P[a][b][c - 1][d][e][f];
                                }

                                offer[offset] = 0;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a][b][c][d - 1][e][f])) {
                                    *ptr = price[offset] + P[a][b][c][d - 1][e][f];
                                }

                                offer[offset] = 0;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a][b][c][d][e - 1][f])) {
                                    *ptr = price[offset] + P[a][b][c][d][e - 1][f];
                                }

                                offer[offset] = 0;
                                offer[++offset] = 1;
                                if (isOfferOk(offer, a, b, c, d, e, f) &&
                                    (*ptr > price[offset] + P[a][b][c][d][e][f - 1])) {
                                    *ptr = price[offset] + P[a][b][c][d][e][f - 1];
                                }

                                // for special offer
                                // reset offer vector
                                for (auto &ofr:offer) {
                                    ofr = 0;
                                }
                                for (const auto &sp:special) {
                                    for (int i = sp.size() - 2; i >= 0; --i) {
                                        offer[i] = sp[i];
                                    }

                                    if (isOfferOk(offer, a, b, c, d, e, f)) {
                                        int prev = P[a - offer[0]][b - offer[1]][c - offer[2]][d - offer[3]][e -
                                                                                                             offer[4]][
                                                f - offer[5]];
                                        if ((INF != prev) && (*ptr > sp.back() + prev)) {
                                            *ptr = sp.back() + prev;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return P[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }

    static bool
    isOfferOk(const vector<int> &offer, const int a, const int b, const int c, const int d, const int e, const int f) {
        return (offer[0] <= a) && (offer[1] <= b) && (offer[2] <= c) && (offer[3] <= d) && (offer[4] <= e) &&
               (offer[5] <= f);
    }
};

int main() {
    /*
    vector<int> price = {2, 5};
    vector<vector<int>> special = {
            {3, 0, 5},
            {1, 2, 10},
    };
    vector<int> needs = {3, 2};
     */
    /*
    vector<int> price = {2, 3, 4};
    vector<vector<int>> special = {
            {1, 1, 0, 4},
            {2, 2, 1, 9},
    };
    vector<int> needs = {1, 2, 1};
     */
    vector<int> price = {4, 3, 2, 9, 8, 8};
    vector<vector<int>> special = {
            {1, 5, 5, 1, 4, 0, 18},
            {3, 3, 6, 6, 4, 2, 32},
    };
    vector<int> needs = {6, 5, 5, 6, 4, 1};

    //cout << Solution::INF << endl;
    cout << Solution::shoppingOffers(price, special, needs) << endl;


    return 0;
}