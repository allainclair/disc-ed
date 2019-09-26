## Listas

### Implementação

Formas de implementar listas.

#### Estática

A lista é previamente criada, logo seu tamanho é definido logo no começo.

![lista-estatica](../images/list/lista-estatica.svg)

#### Dinâmica

A lista pode ser iniciada sem elementos, e seu tamanho pode aumentar e diminuir
de acordo com a necessidade do usuário da lista.

Uma lista dinâmica bem conhecida é a **lista ligada**.

![lista-dinamica](../images/list/lista-dinamica.svg)

#### Lista ligada

Esse tipo de lista **não são acessadas por índices**, apenas é possível "caminhar"
pela lista para manipular elas, ou seja, para ler, adicionar, modificar e excluir
elementos da lista ligada.

![linked-list](../images/list/linked-list.svg)

Geralmente são implementadas de forma dinâmica e não contígua.

Usa-se registros com campos que apontam para outros registros para ligar os nós
da lista. Registro com campos **`valor`** e **`próximo`**.

![linked-list-reg](../images/list/linked-list-reg.svg)

#### Inserções no início

![insercao-inicio](../images/list/insercao-inicio.svg)

#### Inserções no final

![insercao-final](../images/list/insercao-final.svg)

#### Inserções ordenadas

#### Remoções

![remocoes](../images/list/remocoes.svg)


#### Codes

Alguns códigos de lista ligada: https://www.zentut.com/c-tutorial/c-linked-list/
