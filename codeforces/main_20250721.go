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

func printYES() {
	fmt.Println("YES")
}

func bs(b []int, target int, a int) int{
	l :=0
	r:=len(b)-1
	ans := -1
	for {
		if l>r{
			return ans
		}
		mid:=(l+r)/2
		if b[mid]-a>=target{
			ans = mid
			r = mid-1
		} else{
			l = mid+1
		}
	}	
	return ans
}

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	var m int
	Fscan(in, &n)
	Fscan(in, &m)
	a:=make([]int, n)
	b:=make([]int, m)
	for i:=0;i<n;i++{
		Fscan(in, &a[i])
	}
	for i:=0;i<m;i++{
		Fscan(in, &b[i])
	}
	sort.Ints(b)
	// fmt.Println(b)
	pre:=-0x3f3f3f3f
	for i:=0;i<n;i++{
		if i == 0{
			pre = min(b[0] - a[0],a[0])
		} else {
			target := pre
			pos := bs(b,target,a[i])
			if pos == -1 && a[i]<target{
				fmt.Println("NO")
				return
			} else if pos == -1{
				pre=a[i]
			} else {
				if a[i]<b[pos]-a[i]{
					if a[i]<pre{
						pre = b[pos]-a[i]
					} else{
						pre = a[i]
					}
				} else{
					pre = b[pos] - a[i]
				}
				
			}
		}
	}
	fmt.Println("YES")

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
