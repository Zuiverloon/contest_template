// https://codeforces.com/problemset/problem/385/B

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

func solve(cas int, in io.Reader, out io.Writer) {
	// enumerate i and find the nearest 'bear'
	var s string
	Fscan(in, &s)
	n := len(s)
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = -1
	}
	vp := 0
	for i := 0; i < n-3; i++ {
		if s[i:i+4] == "bear" {
			v[vp] = i + 3
			vp += 1
		}
	}
	vp = 0
	ans := 0
	for i := 0; i < n; i++ {
		for {
			if vp < n && v[vp] != -1 && v[vp]-3 < i {
				vp += 1
			} else {
				break
			}
		}
		if v[vp] != -1 {
			ans += n - v[vp]
		}

	}
	fmt.Println(ans)
}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	output := os.Stdout
	//Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, output)
	}

}
