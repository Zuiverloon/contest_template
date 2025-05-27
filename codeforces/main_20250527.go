/**
https://codeforces.com/problemset/problem/1133/D
*/

package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strconv"
)

// func readLine() string {
// 	reader := bufio.NewReader(os.Stdin)
// 	text, _ := reader.ReadString('\n')
// 	return strings.Trim(text, "\n")
// }

// func printArr(arr []int) {
// 	n := len(arr)
// 	for id, i := range arr {
// 		Printf("%d", i)
// 		if id < n-1 {
// 			Printf(" ")
// 		} else {
// 			Printf("\n")
// 		}
// 	}
// }

// func readIntArray() []int {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]int, len(sli))
// 	for i, s := range sli {
// 		ret[i], _ = strconv.Atoi(s)
// 	}
// 	return ret
// }

// func readInt() int {
// 	text := readLine()
// 	ret, _ := strconv.Atoi(text)
// 	return ret
// }

// func readStringArray() []string {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]string, len(sli))
// 	for i, s := range sli {
// 		ret[i] = s
// 	}
// 	return ret
// }

func ioSample(in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)

	Fprint(out, 1)
}

func gcd(a int, b int) int {
	//fmt.Println(a, b)
	if a < b {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	Fscan(in, &n)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &a[i])
	}
	for i := 0; i < n; i++ {
		Fscan(in, &b[i])
	}

	mp := make(map[string]int)
	bd := 0
	for i := 0; i < n; i++ {
		if a[i] == 0 && b[i] == 0 {
			bd++
		} else if a[i] == 0 {
			continue
		} else if b[i] == 0 {
			mp["0"]++
		} else {
			t1 := 0
			t2 := 0
			neg := ""
			if a[i] > 0 && b[i] > 0 {
				t1 = a[i]
				t2 = b[i]
			} else if a[i] > 0 && b[i] < 0 {
				neg = "-"
				t1 = a[i]
				t2 = -b[i]
			} else if a[i] < 0 && b[i] > 0 {
				neg = "-"
				t1 = -a[i]
				t2 = b[i]
			} else {
				t1 = -a[i]
				t2 = -b[i]
			}
			g := gcd(t1, t2)
			// fmt.Println(g, t1, t2)
			key := neg + strconv.FormatInt(int64(t1/g), 10) + "_" + strconv.FormatInt(int64(t2/g), 10)
			// fmt.Println(key)
			mp[key]++
		}
	}
	ans := bd
	for _, value := range mp {
		if value+bd > ans {
			ans = value + bd
		}
	}
	Fprint(out, ans)

}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	//Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, os.Stdout)
	}

}
