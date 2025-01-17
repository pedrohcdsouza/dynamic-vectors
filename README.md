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
  <li>Construtor</li>
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
  <li>Destrutor</li>
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
</table>
