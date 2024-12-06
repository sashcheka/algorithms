#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MOD = 23;     

int modpow(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while(b > 0) {
        if(b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int modinv(int a) {
    for(int i = 1; i < MOD; i++)
        if((a * i) % MOD == 1)
            return i;

    return 1; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i];
        x[i] %= MOD;
        if(x[i] == 0) 
            x[i] = 23;
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> a(n, 0);

    if (m == 1) {
        int sum = 0;

        for(int i = 2; i <= n; i++)
            sum = (sum + (modpow(x[0], i - 1, MOD) * a[i - 1])) % MOD;

        int coeff = 1;
        int rhs = (b[0] - sum + MOD) % MOD;
        a[0] = (rhs * modinv(coeff)) % MOD;

        if(a[0] < 0) 
            a[0] += MOD;
    }

    if (m == 2) {
        int A11 = 1; // x1^0
        int A12 = x[0]; // x1^1
        int A21 = 1; // x2^0
        int A22 = x[1]; // x2^1
        int B1 = b[0];
        int B2 = b[1];

        int det = (A11 * A22 - A12 * A21 + MOD) % MOD;
        if(det == 0) {
            cout << "No solution" << endl;
            return 0;
        }
        int inv_det = modinv(det);

        int x1 = ((B1 * A22 - A12 * B2 + MOD) % MOD * inv_det) % MOD;
        int x2 = ((A11 * B2 - B1 * A21 + MOD) % MOD * inv_det) % MOD;

        a[0] = (x1 + MOD) % MOD;
        a[1] = (x2 + MOD) % MOD;
    } 

    if (m == 3) {
        int A[3][3];
        int B[3];
        for(int i = 0; i < 3; i++) {
            A[i][0] = 1;
            A[i][1] = x[i];
            A[i][2] = (x[i] * x[i]) % MOD;
            B[i] = b[i];
        }

        int det = (A[0][0] * (A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
                   A[0][1] * (A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
                   A[0][2] * (A[1][0]*A[2][1] - A[1][1]*A[2][0])) % MOD;
        det = (det + MOD) % MOD;
        int inv_det = modinv(det);

        int det_x = (B[0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
                     A[0][1]*(B[1]*A[2][2] - A[1][2]*B[2]) +
                     A[0][2]*(B[1]*A[2][1] - A[1][1]*B[2])) % MOD;
        det_x = (det_x + MOD) % MOD;

        int det_y = (A[0][0]*(B[1]*A[2][2] - A[1][2]*B[2]) -
                     B[0]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
                     A[0][2]*(A[1][0]*B[2] - B[1]*A[2][0])) % MOD;
        det_y = (det_y + MOD) % MOD;

        int det_z = (A[0][0]*(A[1][1]*B[2] - B[1]*A[2][1]) -
                     A[0][1]*(A[1][0]*B[2] - B[1]*A[2][0]) +
                     B[0]*(A[1][0]*A[2][1] - A[1][1]*A[2][0])) % MOD;
        det_z = (det_z + MOD) % MOD;

        a[0] = (det_x * inv_det) % MOD;
        a[1] = (det_y * inv_det) % MOD;
        a[2] = (det_z * inv_det) % MOD;

        a[0] = (a[0] + MOD) % MOD;
        a[1] = (a[1] + MOD) % MOD;
        a[2] = (a[2] + MOD) % MOD;
    }

    string password;
    for(int i = 0; i < n; i++)
        password += a[i] + 'a';

    cout << password << endl;

    return 0;
}
