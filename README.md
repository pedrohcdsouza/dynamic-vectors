[Português](README.md) | [English](README.en.md)

<h1 align=center>Listas dinâmicas e encadeadas</h1>

<h3><strong><em>Introdução</em></strong></h3>

<h4>Este é um Projeto Acadêmico da disciplina de Algoritmos do IFRN, com o objetivo de:</h4> 

<ul>
  <li>Compreender o funcionamento de estrutura de dados fundamentais, especificamente listas dinâmicas e duplamente ligadas</li>
  <li>Desenvolver implementações práticas utilizando a linguagem C++ e aplicando conceitos de programação orientada a objetos.</li>
  <li>Avaliar a eficiência das operações básicas, como inserção, remoção, busca e iteração.</li>
</ul>

<table>
<tr><td align=center><strong>Lista dinâmica</strong></td><td align=center><strong>Lista encadeada</strong></td></tr>
<tr><td>Uma estrutura de dados que armazena elementos de forma contígua na memória.</td><td>Uma estrutura de dados que armazena elementos em nós, com ponteiros entre eles.</td></tr>
<tr><td>Acesso rápido aos elementos pela posição.</td><td>Facilidade de inserção e remoção, sem necessidade de realocação.</td></tr>
</table>

<h3><strong><em>Métodos</em></strong></h3>
<ul>
  <li>Constructor</li>
</ul>

<table>
<tr>
<td><pre>
array_list() {
  this->size_ = 0;
  this->capacity_ = 8;
  this->data = new int[capacity_];                           
}</pre></td>

<td><pre>
linked_list() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size_ = 0;                                             
}
</pre></td>
</tr>

<tr>
  <td>O método construtor é responsável pela criação de uma lista estática, inicializando os valores de size e capacity para garantir o gerenciamento adequado da estrutura de dados.</td>
  <td>O método construtor é responsável pela criação de um nó a partir da estrutura int_node, que contém o endereço do próximo nó, o endereço do nó anterior e o valor armazenado no próprio nó.</td>
</tr>

</table>

<ul>
  <li>Destructor</li>
</ul>

<table>
  <tr>
<td><pre>
~array_list() {
  delete[] data;
  size_ = 0;
  capacity_ = 8;                                              
  data = new int[capacity_];
} 
</pre></td>

<td><pre>
~linked_list() {
  int_node* del_node = head;
    while (head != nullptr) {
      head = head->next;
      delete del_node;                                         
    }
  tail = nullptr;
  size_ = 0;
}
</pre></td>
  </tr>
  <tr>
    <td>O destrutor apenas apaga a lista e reseta todas as variáveis.</td>
    <td>O destrutor percorre do primeiro elemento (HEAD) até o último elemento (TAIL) e apaga todo encandeamento.</td>
  </tr>
</table>

<ul>
  <li>Increase_capacity</li>
</ul>

<table>
  <tr>
<td><pre>
void increase_capacity() {
  capacity_ *= 2;
  int *new_node = new int[capacity_];
    for (unsigned int i = 0; i < size_; ++i) {
      new_node[i] = data[i];
      }
  data = new_node;                                            
}       
</pre></td>
<td><pre>
                     .                                        
</pre></td>
  </tr>
  <tr>
    <td>O método consiste na criação de uma nova lista, quando a anterior está cheia, com maior capacidade.</td>
    <td>Não precisa de aumentar a capacidade tendo em vista que seus elementos são alocados dinâmicamente, separados na memória.</td>
  </tr>
</table>

<ul><li>Size</li></ul>

<table>
  <tr>
<td><pre>
unsigned int size() {
  return size_;                                                                                                             .        
}
</pre></td>
  </tr>
  <tr><td>Retorna o tamanho da lista, armazenado dentro da classe/struct.</td></tr>
</table>

<ul><li>Capacity</li></ul>

<table>
  <tr>
<td><pre>
unsigned int capacity() {
  return capacity_;                                           
}
</pre></td>
<td><pre>
                                                             .
</pre></td>
  </tr>
  <tr><td>Retorna a atual capacidade da lista</td><td>Não há necessidade de capacidade.</td></tr>
</table>

<ul><li>Insert_at</li></ul>

<table>
  <tr>
<td><pre>
bool insert_at(unsigned int index, int value){
  if (index > size_ || index < 0){
      return false; 
  }
  int_node *new_node = new int_node;
  new_node->current = value;
  new_node->next = nullptr;
  new_node->prev = nullptr;
  if (index == 0){
      if (head == nullptr){
          head = tail = new_node;
      }else{
          new_node->next = head;
          head->prev = new_node;
          head = new_node;
      }
  }else if (index == size_){
      new_node->prev = tail;
      tail->next = new_node;
      tail = new_node;
  }
  else{
      int_node *current = head;
      for (unsigned int i = 0; i < index; i++){
          current = current->next;
      }
      new_node->prev = current->prev;
      new_node->next = current;
      current->prev->next = new_node;
      current->prev = new_node;
  }
  
  size_++;
  return true;                                                 .                        
}
</pre></td>

<td><pre>
bool insert_at(unsigned int index, int value) {
  if (index > size_ or index < 0){
        return false;
    }

  if (size_ == capacity_){
        increase_capacity();
    }

  for (unsigned int i = size_; i > index; i--)
    {
        data[i] = data[i - 1];
    }

  data[index] = value;

  size_++;

  return true;                                                  .
}
</pre></td>
  </tr>

<tr>
  <td>O método insert_at insere um nó em uma lista duplamente encadeada na posição indicada. Ele verifica a validade do índice, cria o nó e ajusta os ponteiros dos nós adjacentes conforme a posição (início, meio ou fim). O tamanho da lista é incrementado após a inserção.</td>
  <td>
O método insert_at insere um valor no vetor na posição especificada, movendo os elementos à direita para abrir espaço. Se necessário, aumenta a capacidade do vetor. O tamanho é incrementado após a inserção.</td>
</tr>
<tr>
  <td>Complexidade: O tempo de execução é O(n), pois no pior caso é necessário percorrer a lista até o índice desejado, onde n é o número de elementos na lista.</td>
  <td>Complexidade: O tempo de execução é O(n), onde n é o número de elementos no vetor, pois no pior caso, todos os elementos após o índice especificado precisam ser movidos uma posição à direita.</td>
</tr>
<tr></tr>
</table>
