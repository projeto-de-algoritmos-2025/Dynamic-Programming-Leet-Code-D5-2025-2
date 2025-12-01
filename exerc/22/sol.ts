// Sn = "(" + Sd + ")" + Sf
/* dp[0] = [""]
   dp[1] =
    - j=0: ( + dp[0] + ) + dp[0] -> ()
   dp[2]
    - j=0: ( + dp[0] + ) + dp[1] -> ()()
    - j=1: ( + dp[1] + ) + dp[0] -> (())

   ...
*/

function generateParenthesis(n: number): string[] {
  const dp: Array<Array<string>> = new Array(n + 1).fill(null).map(() => []);

  dp[0] = [""];

  for (let i = 1; i <= n; i++) {
    for (let j = 0; j < i; j++) {
      for (const d of dp[j]) {
        for (const f of dp[i - 1 - j]) {
          dp[i].push("(" + d + ")" + f);
        }
      }
    }
  }

  return dp[n];
}

const main = () => {
  console.log(generateParenthesis(3));
};
