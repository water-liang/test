package main

func moveZeroes(nums []int) {

	for front, rear := 0, len(nums)-1; front < rear; {
		if nums[front] == 0 {
			nums[front], nums[rear] = nums[rear], nums[front]
			rear--
		} else {
			front++
		}
	}

}
