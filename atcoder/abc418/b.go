package main

// 

import (
	"bufio"
	. "fmt"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	// "sync"
	// "sort"
	"math"
)

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	return strings.Trim(text, "\n")
}

func printArr(arr []int) {
	n := len(arr)
	for id, i := range arr {
		Printf("%d", i)
		if id < n-1 {
			Printf(" ")
		} else {
			Printf("\n")
		}
	}
}

func readIntArray() []int {
	text := readLine()
	sli := strings.Split(text, " ")
	ret := make([]int, len(sli))
	for i, s := range sli {
		ret[i], _ = strconv.Atoi(s)
	}
	return ret
}

func readInt() int {
	text := readLine()
	ret, _ := strconv.Atoi(text)
	return ret
}

func readStringArray() []string {
	text := readLine()
	sli := strings.Split(text, " ")
	ret := make([]string, len(sli))
	for i, s := range sli {
		ret[i] = s
	}
	return ret
}

func gcd(x int, y int) int {
	if x<0{
		return gcd(-x,y)
	}
	if y< 0{
		return gcd(x,-y)
	}
	if x == 0 {
		return y
	}
	return gcd(y%x,x)
}





func solve(cas int, in io.Reader, out io.Writer) {
	var s string
	Fscan(in, &s)
	n:=len(s)
	presum:=make([]int, n+1)
	pre:=0
	for i:=0;i<n;i++{
		if s[i] == 't' {
			pre++
			
		}
		presum[i+1] = pre
	}
	// fmt.Println(presum)
	ans:=0.0
	for i:=0;i<n;i++{
		tans:=0.0
		for j:=0;j<=i-2;j++{
			if s[i] == s[j] && s[i] == 't' {
				tans = (float64(presum[i+1] - presum[j]-2)*1.0) / float64((i-j+1-2)*1.0)
				// fmt.Println("i j tans=",i,j,tans)
				ans=math.Max(ans,tans)
			}
			
		}
	}
	fmt.Println(ans)

	


}


func main() {
	n := 1
	

	// n = readIntArray()[0]
	in:=bufio.NewReader(os.Stdin)
	// Fscan(in, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, in, os.Stdout)
	}

}
