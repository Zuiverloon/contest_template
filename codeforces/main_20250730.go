package main

// https://codeforces.com/problemset/problem/2052/F

import (
	"bufio"
	"fmt"
	. "fmt"
	"io"
	"os"
	// "sort"
)

func printArr[T any](arr []T){
	l := len(arr)
	for i:=0;i<l;i++{
		fmt.Print(arr[i])
		if i<l-1{
			fmt.Print(" ")
		} else {
			fmt.Print("\n")
		}
	}
}



func ioSample(in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)

	Fprint(out, 1)
}

func printYES() {
	fmt.Println("YES")
}
func printNO() {
	fmt.Println("NO")
}

func printYes() {
	fmt.Println("Yes")
}
func printNo() {
	fmt.Println("No")
}
// sort sort.Ints()

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	Fscan(in, &n)
	var s1,s2 string
	Fscan(in, &s1)
	Fscan(in, &s2)
	dp1:=make([]int, n)
	// ##
	// ##
	dp2:=make([]int, n)
	// ##
	// #?
	dp3:=make([]int, n)
	// #?
	// ##
	// dp4:=make([]int, n)
	// // ##
	// // ??
	// dp5:=make([]int, n)
	// ??
	// ##
	for i:=0;i<n;i++{
		// dp1[i] = -1
		// dp2[i] = -1
		// dp2[i] = -1
		// dp2[i] = -1
		// dp2[i] = -1
		if i == 0{
			if (s1[0] == '#' && s2[0] == '#') || (s1[0] == '.' && s2[0] == '.') {
				dp1[0] = 1
			}
			if s1[0] == '#' && s2[0] == '.' {
				dp2[0] = 1
			}
			if s1[0] == '.' && s2[0] == '#' {
				dp3[0] = 1
			}
		} else {
			if (s1[i] == '.' && s2[i] == '.') || (s1[i] == '#' && s2[i] == '#'){
				dp1[i] = dp1[i-1]
			}
			if (s1[i] == '.' && s2[i] == '.') && (s1[i-1] == '.' && s2[i-1] == '.'){
				pre:=0
				if i-2>=0{
					pre = dp1[i-2]
				}
				if pre>0 || i == 1 {
					dp1[i] = max(dp1[i],2+pre)
				}
			}
			if (s1[i] == '#' && s2[i] == '#') {
				dp1[i] = max(dp1[i],dp1[i-1])
			}
			if (s1[i] == '.' && s1[i-1] == '.') && (s2[i] == '#') {
				dp1[i] = max(dp1[i],dp3[i-1])
			}
			if (s2[i] == '.' && s2[i-1] == '.') && (s1[i] == '#') {
				dp1[i] = max(dp1[i],dp2[i-1])
			}
			// dp2
			if (s1[i] == '#') {
				dp2[i] = max(dp2[i],dp1[i-1])
			}
			if (s1[i] == s1[i-1]){
				dp2[i] = max(dp2[i],dp3[i-1])
			}
			// dp3
			if (s2[i] == '#') {
				dp3[i] = max(dp3[i],dp1[i-1])
			}
			if (s2[i] == s2[i-1]){
				dp3[i] = max(dp3[i],dp2[i-1])
			}
			// fmt.Println("dp1",i,dp1[i])
			// fmt.Println("dp2",i,dp2[i])
			// fmt.Println("dp3",i,dp3[i])
		}
	}
	if dp1[n-1] == 0{
		fmt.Println("None")
	} else if dp1[n-1] ==1 {
		fmt.Println("Unique")
	} else {
		fmt.Println("Multiple")

	}



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
