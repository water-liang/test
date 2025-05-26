package main




type node struct {
	data int
	next *node
}  

type list struct {
	root *node
}

func createList() *list {
	return &list{root: nil}
}

func main(){


}
