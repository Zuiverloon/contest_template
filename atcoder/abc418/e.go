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

var ans []int
var no []int
var nei map[int][]int
var cnt []int

func dfs(o int, fa int, val int){
	// fmt.Println("dfs ",o,fa)
	if no[o] == val{
		ans[val] = 1
	}
	cnt=make([]int, len(ans))
	cnt[val]++
	cnt[no[o]]++
	for _,nxt:=range(nei[o]) {
		if fa == nxt {
			continue
		}
		cnt[no[nxt]]++
		if cnt[no[nxt]]>=2 {
			ans[no[nxt]] = 1
		}
	}
	cnt = nil
	for _,nxt:=range(nei[o]) {
		if fa == nxt {
			continue
		}
		dfs(nxt,o,no[o])
	}
	// for ky,vl:=range(cnt) {
	// 	if vl>=2 {
			
	// 	}
	// }
}

func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	var t string
	Fscan(in, &n)
	Fscan(in, &t)
	zero:=0
	one:=0
	ans := 0
	for i:=0;i<n;i++{
		nzero:=0
		none:=0
		if t[i] == '0'{
			nzero = 1+one
			none = zero
		} else {
			nzero = zero
			none = one+1
		}
		zero = nzero
		one = none
		ans+=one
		// fmt.Println("zero one ",zero, one)
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
