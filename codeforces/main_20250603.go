// https://codeforces.com/problemset/problem/1974/C

package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"io"
	"os"
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

func f(mp map[int64]map[int64]int64) int64 {
	var ans int64
	var total int64
	total = 0
	ans = 0
	for _, val := range mp {
		// fmt.Println(s)
		total = 0
		for _, v := range val {
			// fmt.Println(k, v)
			total += v
		}
		for _, v := range val {
			// ans -= v
			ans += v * (total - v)
		}
	}
	// fmt.Println("tmp=", ans/2)

	return ans / 2
}

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	Fscan(in, &n)
	v := make([]int64, n)
	for i := 0; i < n; i += 1 {
		Fscan(in, &v[i])
	}
	var hs int64
	hs = 10000000
	mp1 := make(map[int64]map[int64]int64)
	mp2 := make(map[int64]map[int64]int64)
	mp3 := make(map[int64]map[int64]int64)
	for i := 0; i < n-2; i += 1 {
		a0 := v[i]
		a1 := v[i+1]
		a2 := v[i+2]

		if mp1[a0*hs+a1] == nil {
			mp1[a0*hs+a1] = make(map[int64]int64)
		}
		mp1[a0*hs+a1][a2] += 1
		if mp2[a0*hs+a2] == nil {
			mp2[a0*hs+a2] = make(map[int64]int64)
		}
		mp2[a0*hs+a2][a1] += 1
		if mp3[a1*hs+a2] == nil {
			mp3[a1*hs+a2] = make(map[int64]int64)
		}
		mp3[a1*hs+a2][a0] += 1
	}
	var ans int64
	ans = 0
	// fmt.Println("processing mp1")
	ans += f(mp1)
	// fmt.Println("processing mp2")
	ans += f(mp2)
	// fmt.Println("processing mp3")
	ans += f(mp3)
	fmt.Println(ans)
}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	output := os.Stdout
	Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, output)
	}

}
