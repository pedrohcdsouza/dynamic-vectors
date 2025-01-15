#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
int* data;
unsigned int size_, capacity_;

void increase_capacity() {
    capacity_ *= 2;
    int *new_node = new int[capacity_];

    for (unsigned int i = 0; i < size_; ++i) {
        new_node[i] = data[i];
    }

    delete[] data;
    data = new_node;
}

public:
array_list() {
    this-> size_ = 0;
    this-> capacity_ = 8;
    this-> data = new int[capacity_];
}
~array_list() {
    delete[] data;
}
unsigned int size() {
    return size_;
} 
unsigned int capacity() {
    return capacity_;
}
double percent_occupied() {
   return (static_cast<double>(size_) / static_cast<double>(capacity_)) * 100;
} 

bool insert_at(unsigned int index, int value) {
   if(index > size_) {
       return false;
   }

    if(size_ == capacity_) {
        increase_capacity();
    }

       for(std::size_t i = size_; i > index; --i) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    ++size_;
    return true;
} 
bool remove_at(unsigned int index) {
      if(index > size_) {
       return false;
   }

       for(std::size_t i = index; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }
    
     --size_;
     return true;
} 

int get_at(unsigned int index) {
    if (index >= size_) { 
        return -1;
    }
    return data[index];
}

void clear() {
    delete[] data; 
    size_ = 0;
    capacity_ = 8;
    data = new int[capacity_];
}

void push_back(int value) {
    if(size_ == capacity_) {
        increase_capacity();
    }

    data[size_] = value;
    ++size_;
} 
void push_front(int value) {
    if(size_ == capacity_) {
        increase_capacity();
    }


    for(int i = size_; i > 0; --i) {
        data[i] = data[i - 1];
    }

    data[0] = value;
    ++size_;
}
bool pop_back() {
    if(size_ == 0) {
        return false;
    }

    --size_;
    return true;
}
bool pop_front() {
    if(size_ == 0) {
        return false;
    }

    for(std::size_t i = 0; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size_;
    return true;
}
int back(){
    return data[size_ - 1];
}
int front(){
       return data[0];
} 
bool remove(int value) {
    for(std::size_t i = 0; i < size_; ++i) {
        if(data[i] == value) {
            for(std::size_t j = i; j < size_ - 1; ++j) {
                data[j] = data[j + 1];
            }

            --size_;
            return true;
        }
    }
    return false;
}
int find(int value) {
    for (std::size_t i = 0; i < size_; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}
int count(int value) {
    int count = 0;
    for (std::size_t i = 0; i < size_; ++i) {
        if (data[i] == value) {
            ++count;
        }
    }
    return count;
} 
int sum() {
    int sum = 0;
    for (std::size_t i = 0; i < size_; ++i) {
        sum += data[i];
    }
    return sum;

} 
};
#endif // __ARRAY_LIST_IFRN__