package main

import (
	"fmt"
	"sync"
)

var myMutex sync.Mutex

var myCount int

func increment() {
	myMutex.Lock()
	fmt.Println(myCount)
	myMutex.Unlock()

}

func main() {
	myCount = 0
	// 创建三个通道用于同步控制
	// chanA := make(chan int) recv和send的返回是在对面收到后返回
	chanA := make(chan int, 1)
	chanB := make(chan int, 1)
	chanC := make(chan int, 1)
	var wg sync.WaitGroup

	print := func(ch <-chan int, next chan<- int, char string) {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			<-ch            // 等待信号
			fmt.Print(char) // 打印字符
			next <- i
			// 通知下一个协程
		}
	}


	wg.Add(3)
	go print(chanA, chanB, "a")
	go print(chanB, chanC, "b")
	go print(chanC, chanA, "c")

	// 启动协程链
	chanA <- 1 // 触发第一个协程
	wg.Wait()
	fmt.Println()
}
