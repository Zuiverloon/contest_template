// https://codeforces.com/problemset/problem/1076/A
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

func bs(presum []int64, pre int64, j int, x int64) int {
	l := j
	r := len(presum) - 1
	ans := len(presum)
	for l <= r {
		mid := (l + r) / 2
		if presum[mid]-pre > x {
			r = mid - 1
			ans = mid
		} else {
			l = mid + 1
		}
	}
	return ans
}

func f(s string) int {
	ans:=-1
	end := s[len(s)-1]
	for i:=0;i<len(s)-1;i++{
		if int(s[i] - '0') %2 == 0{
			if s[i]<end{
				return i
			} else{
				ans = i
			}
		}
	}
	return ans
}

func solve(cas int, in io.Reader, out io.Writer) {
	// s[0..n]
	// iterate through s
	// if s[i] is a even digit, compare with the last, 
	// if >, then swap & find the ans
	// if <, note down the temp ans, and continue iteration
	var n int
	Fscan(in, &n)
	var s string
	Fscan(in, &s)
	ans := make([]byte, n-1)
	remove:=n-1
	for i:=0;i<n-1;i++{
		if s[i] > s[i+1]{
			remove = i
			break
		}
	}
	ansp:=0
	for i:=0;i<n;i++{
		if i!=remove{
			ans[ansp] = s[i]
			ansp+=1
		}
	}
	fmt.Println(string(ans))
	
	
}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	output := os.Stdout
	// Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, output)
	}

}
