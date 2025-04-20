package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for test := 0; test < t; test++ {
		var n int
		fmt.Fscan(in, &n)

		score := make(map[string]int)
		action := ""

		in.ReadString('\n')

		for i := 0; i < n; i++ {
		    line, _ := in.ReadString('\n')
		    parts := strings.Fields(line)

		    var a, b, x string
		    mine := false
		    point := 0

		    if len(parts) == 4 {
		        a = parts[0][:len(parts[0])-1]
		        b = parts[1]
		        mine = parts[2] == "am"
		        point = 1
		        x = parts[3][:len(parts[3])-1]
		    } else { // len(parts)==5
		        a = parts[0][:len(parts[0])-1]
		        b = parts[1]
		        mine = parts[2] == "am"
		        point = -1
		        x = parts[4][:len(parts[4])-1]
		    }
		    action = x

		    if _, ok := score[a]; !ok {
		        score[a] = 0
		    }
		    if !mine {
		        if _, ok := score[b]; !ok {
		            score[b] = 0
		        }
		    }

		    if mine {
		        if point == 1 {
		            score[a] += 2
		        } else {
		            score[a] += point
		        }
		    } else {
		        score[b] += point
		    }
		}


		maxScore := -1 << 31
		for _, v := range score {
			if v > maxScore {
				maxScore = v
			}
		}

		candidates := []string{}
		for k, v := range score {
			if v == maxScore {
				candidates = append(candidates, k)
			}
		}
		sort.Strings(candidates)

		for _, name := range candidates {
			fmt.Fprintf(out, "%s is %s.\n", name, action)
		}
	}
}
