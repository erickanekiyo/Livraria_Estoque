Plataforma de Gestão de Estoque de Livraria

Objetivo do Projeto:

  Este projeto é um sistema de gerenciamento de estoque de livros desenvolvido em C. Seu objetivo é ter o controle de estoque de uma livraria, permitindo registrar novos livros, alterar a quantidade em estoque, consultar qual livro está presente e gerar relatórios do estoque. Podendo ser usado para um controle simples dos livros que a livraria detém.
  
Como Compilar e Executar:

  Compilação - Para compilar o programa, use o GCC com os arquivos organizados nas pastas src e include. Execute o seguinte comando de compilação no terminal:

        gcc -o estoque main.c src/cadastro.c src/consulta.c src/relatorio.c src/atualz_qtd.c src/menu.c -Iinclude

  Execução -  Após a compilação, execute o programa com o comando:

        ./estoque

Como Usar a Plataforma:

  Cadastro de Livros:
  
      Ao acessar o menu, você pode cadastrar novos livros no sistema, inserindo informações como código, título, autor, descrição (opcional), preço unitário (necessário usar virgula caso queira colocar valores com bases decimais). O código do livro é único, e o sistema não permitirá cadastrar dois livros com o mesmo código.

  Alteração no Estoque:
  
      Você pode alterar a quantidade de livros no estoque, seja para adicionar ou remover livros. Para isso, basta informar o código do livro e a quantidade desejada. Potanto, todos os livros são cadastrados com quantidade 0, precisando informar quantos daquele livro foram adicionados ou retirados através dessa função.

  Consulta de Estoque:
  
      O sistema permite consultar livros no estoque tanto pelo código quanto pelo nome. As pesquisas são feitas de maneira eficiente, e a comparação entre os nomes dos livros é realizada de forma insensível a maiúsculas e minúsculas.

Relatório do Estoque:

      O programa permite gerar um relatório completo do estoque da livraria, incluindo todos os livros cadastrados. O relatório é gerado com a data atual no nome do arquivo e é salvo em formato de texto. O conteúdo inclui informações sobre o código, título, autor, preço e quantidade de cada livro.

Estrutura dos Arquivos:

      livros.bin: Armazena os dados em binario dos livros, como código, título, autor, preço e quantidade. Este arquivo é utilizado para leitura e escrita das informações de livros cadastrados.

      relatorio_estoque_<data>.txt: Armazena o relatório do estoque, gerado com as informações dos livros no formato de texto. O nome do arquivo inclui a data da geração do relatório.

Detalhes Técnicos:

      Cadastro de Livro: Cada livro possui um código único. Caso tente cadastrar um livro com um código já existente, o sistema irá alertar e não permitirá a duplicação.

      Alteração no Estoque: A quantidade de livros pode ser alterada a qualquer momento. O sistema realiza validações para garantir que os valores de quantidade sejam positivos.

Observações:

      Certifique-se de inserir os valores corretamente, especialmente para o preço (utilizando ponto ao invés de vírgula para valores decimais).

      O sistema está configurado para funcionar em um terminal, e todas as entradas de dados são feitas via linha de comando.
