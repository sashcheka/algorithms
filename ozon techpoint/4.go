package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    in  := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    defer out.Flush()

    var t int
    fmt.Fscan(in, &t)
    for test := 0; test < t ; test++ {
        var n, m int
        fmt.Fscan(in, &n, &m)

        freq := make(map[string]int, n)
        var pairs int64

        diagram := make([]int64, m)
        diff := make([]int64, m - 1)
        rev_diff  := make([]int64, m - 1)

        for i := 0; i < n; i++ {
            for j := 0; j < m; j++ {
                fmt.Fscan(in, &diagram[j])
            }

            for j := 0; j + 1 < m; j++ {
                diff[j] = diagram[j + 1] - diagram[j]
                rev_diff[m - 2 - j] = diff[j]
            }

            key := fmt.Sprint(diff)
            rev_key := fmt.Sprint(rev_diff)

            pairs += int64(freq[rev_key])
            freq[key]++
        }

        fmt.Fprintln(out, pairs)
    }
}
