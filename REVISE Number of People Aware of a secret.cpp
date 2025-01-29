#define ll long long int
const ll MOD = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> peopleWhoLearned(n, 0);
        peopleWhoLearned[0] = 1;

        for (int day = 0; day < n; day++) {
            for (int shareDay = day + delay; shareDay < day + forget && shareDay < n; shareDay++) {
                peopleWhoLearned[shareDay] = (peopleWhoLearned[shareDay] % MOD + peopleWhoLearned[day] % MOD) % MOD;
            }
        }

        ll totalPeopleRemembering = 0;
        for (int day = n - forget; day < n; day++) {
            totalPeopleRemembering = (totalPeopleRemembering % MOD + peopleWhoLearned[day] % MOD) % MOD;
        }

        return totalPeopleRemembering;
    }
};
