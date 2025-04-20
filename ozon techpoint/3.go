package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    defer out.Flush()

    var t int
    fmt.Fscan(in, &t)
    for tc := 0; tc < t; tc++ {
        var n, k int
        fmt.Fscan(in, &n, &k)

        a := make([]int64, n)
        for i := 0; i < n; i++ {
            fmt.Fscan(in, &a[i])
        }

        diff := make([]int64, n + 1)
        var active int64
        ok := true

        for i := 0; i < n; i++ {
            active += diff[i]

            need := a[i] - active
            if need < 0 {
                ok = false
                break
            }
            if need > 0 {
                if i + k > n {
                    ok = false
                    break
                }
                active += need
                diff[i + k] -= need
            }
        }

        if ok {
            fmt.Fprintln(out, "YES")
        } else {
            fmt.Fprintln(out, "NO")
        }
    }
}
