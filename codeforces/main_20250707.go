// https://codeforces.com/problemset/problem/2118/C
package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"io"
	"os"
	"sort"
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

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	var k int64
	Fscan(in, &n)
	Fscan(in, &k)
	arr := make([]int64, 0)
	ans := 0
	for i := 0; i < n; i++ {
		var t int64
		t = 0
		Fscan(in, &t)
		var base int64
		base = 1
		for i := 0; i < 63; i++ {
			if base&t == 0 {
				arr = append(arr, base)
				// fmt.Println("Add ", base)
			} else {
				ans++
			}
			base <<= 1
		}

	}
	// fmt.Println("Temp ans=", ans)
	sort.Slice(arr, func(i, j int) bool { return arr[i] < arr[j] })
	for _, i := range arr {
		// fmt.Println("i=", i)
		if i <= k {
			ans++
			k -= i
		} else {
			break
		}
	}
	fmt.Println(ans)

	// for (i:=0;i<n;i++){
	// 	t:=0
	// 	Fscan(in,&t)
	// }

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
