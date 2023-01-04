<?php
    if(!isset($_SESSION)) {
        session_start();
    }
    if(isset($_GET['logout'])) {
        unset($_SESSION);
        session_destroy();
        header("Location: index.php");
    }
?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta charset="UTF-8">
  <title>CPE - Coordenação</title>
  <link rel="stylesheet" href="./css/header.css">
  <link rel="stylesheet" href="./css/footer.css">
  <link rel="stylesheet" href="./css/coordenacao.css">
</head>

<body>
  <div class="header">
    <h1>COORDENADORIA DE PESQUISA E EXTENSÃO</h1>
    <img src="./imagens/rural_logo_branco02.png" alt="logo rural">
  </div>

  <div class="cabecalho">
    <h2>Olá, <?php echo $_SESSION['nome'];?>! <a href="?logout"><button type="button">Sair</button></a></h2>
  </div>

  <div class="busca">
    <img src="./imagens/search3.png" alt="Buscar projeto de extensão..." />
    <input type="text" placeholder="Buscar extensão..." class="box" />
    <button class="botaobusca">Buscar</button>
  </div>

  <div class="extensoes">
    <div class="ativas">
      <h3>Extensões</h3>
      <ul>
        <li>
          <p></p>
          <p class="responsavel"><span></span></p>
        </li>
        <li>
          <p></p>
          <p class="responsavel"><span></span></p>
        </li>
      </ul>
    </div>
  </div>

  <footer>
    <div class="rodape">
      <p>Coordenadoria de Pesquisa e Extensão - Universidade Federal Rural do Rio de Janeiro</p>
      <p>UFRRJ © Todos os direiros reservados.</p>
    </div>
  </footer>
</body>

</html>