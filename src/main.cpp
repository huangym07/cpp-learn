#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const int MAXN = 4e3 + 5;

int n;
std::pair<int, int> mnt[MAXN];
long long sum[MAXN], dp[MAXN][MAXN];

int main() {
  std::cin >> n;
  for(int i = 1; i <= n; i++) std::cin >> mnt[i].first >> mnt[i].second;

  std::sort(mnt + 1, mnt + 1 + n);
  
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + mnt[i].second;

  std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, LONG_LONG_MAX));

  dp[1][0] = mnt[1].first;
  dp[1][1] = 0;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(j != 0) {
        dp[i][j] = mnt[i].second >= dp[i - 1][j - 1] 
                    ? 0 : dp[i - 1][j - 1] - mnt[i].second;
      }
      dp[i][j] = std::min(dp[i][j], sum[i - 1] >= mnt[i].first 
                                      ? dp[i - 1][j] : dp[i - 1][j] + std::max(0LL, mnt[i].first - sum[i - 1] - dp[i - 1][j]));
                                      // 这里当 sum[i - 1] < mnt[i].first 时，
                                      // 预支付给前 i - 1 个怪物 dp[i - 1][j] 后
                                      // 要么足够消灭第 i 个怪物
                                      // 要么还需再预支付伤害
                                      // 所以总的预支付伤害为 dp[i - 1][j] + std::max(0LL, mnt[i].first - sum[i - 1] - dp[i - 1][j])
    }
  }

  int ans = 0;
  for(int j = 0; j <= n; j++) {
    if(dp[n][j] == 0) {
      ans = j;
      break;
    }
  }

  std::cout << ans << '\n';

  return 0;
}


/* test case:
    input:
        4
        6 1
        5 2
        4 1
        1 3
    output: 
        1
    解释：
        仅需手动消灭 6 1 
*/