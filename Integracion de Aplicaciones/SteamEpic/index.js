const request = require('request-promise');
const cheerio = require('cheerio');
const puppeteer = require('puppeteer');
const express = require("express");
const app = new express();
const port = 5000;
const cookies = {'birthtime': '568022401'};
app.use(express.json());
app.get("/", function (request, response) {
    response.sendFile("C:/Users/Gilberto/Desktop/React/SteamEpic/html/index.html"); // <---- Cambiar ruta al html
  });
const game = "the outer"; //Input del usuario
var searchEpic = game; 
//searchEpic = searchEpic.toString().trim().replace(" ","%20");
var searchSteam = game;
//searchSteam = searchSteam.toString().trim().replace(" ","%20");

app.post("/busqueda", async function(request, response){
    console.log("got here")
    console.log(request.body);
    /**/ 
    let gameInfoS = await getGameInfo(request.body.game);
    response.send(gameInfoS);
});

async function getGameInfo(game){
    const SteamURL = "https://store.steampowered.com/search/?term=" + game;
    let $ = await request({
        uri: SteamURL,
        transform: body => cheerio.load(body)
    });
    const precioSteam = $('.search_price');
    steamPrice = precioSteam.html().trim();
    console.log(steamPrice);

    const fechaLanzamiento = $('.search_released');
    fecha = fechaLanzamiento.html().trim();
    console.log(fecha);

    const tituloJuego = $('.title');
    tituloG = tituloJuego.html().trim();
    console.log(tituloG);
    
   
    let imagen = $('.search_capsule img').attr('src');
    console.log(imagen);
    
    let enlace = $('#search_resultsRows a').attr('href');
    console.log(enlace);

    const a = $('.search_reviewscore span.search_review_summary').attr('data-tooltip-html');
    b = a;
    console.log(b);
    
    
    const browser = await puppeteer.launch({
        headless: false
    });

    const pageEpic = await browser.newPage();
    await pageEpic.goto("https://www.epicgames.com/store/es-ES/browse?q=" + game + "&sortBy=relevancy&sortDir=DESC&count=40");
    

    const getPriceEpic = await pageEpic.evaluate(()=>{
       const price = document.querySelectorAll('.css-1uf2klp')
        const gamesList = [];
        price.forEach((element) =>{
            gamesList.push(element.innerHTML);
        });
       return gamesList;
   });

   /*const getImg = await pageEpic.evaluate(()=>{
    const foto = document.querySelectorAll('.css-13vabc5')
     const fotolist = [];
     foto.forEach((element) =>{
        fotolist.push(element.getAttribute('src'));
     });
    return fotolist;
});*/

/*const ofertaEpic = await pageEpic.evaluate(()=>{
    const a = document.querySelectorAll('.css-b0xoos')
     const oferta = [];
     a.forEach((element) =>{
        oferta.push(element.innerHTML);
     });
    return oferta;
});
console.log(ofertaEpic[0]);*/

const getGame = await pageEpic.evaluate(()=>{
    const game = document.querySelector('a.css-1jx3eyg');
    let f = game.getAttribute('href');
    return f;
});
console.log(getGame);

const productEpic = await browser.newPage();
    await productEpic.goto("https://www.epicgames.com" + getGame);

    const requisitos = await productEpic.evaluate(()=>{
        const foto = document.querySelectorAll('.css-1uf2klp');
         const fotolist = [];
         //console.log("hola");
         foto.forEach((element) =>{
            fotolist.push(element.innerHTML);
         });
        return fotolist;
    });
    console.log("REQ: " + requisitos[20] + " " + requisitos[22], requisitos[24], requisitos[26] + " " + requisitos[28]);
    let rets = [requisitos[20], requisitos[22], requisitos[24], requisitos[26], requisitos[28]];

    /*for(var i =0; i<requisitos.length; i++){
        console.log(i + " " + requisitos[i]);
    }*/
console.log(rets);






/*for(var i =0; i<getImg.length; i++){
    console.log(getImg[i]);
}*/

   var str = getPriceEpic[2];
    
   rets = rets.toString().trim().replace("&nbsp;"," ");
   rets = rets.toString().trim().replace("<br>"," ");

   str = str.toString().trim().replace("&nbsp;"," ");
   str = str.toString().trim().replace(",",".");

    b=b.toString().trim().replace("<br>"," ");
    console.log("resena : "  + b)

   str = str.toString().trim().replace("MXN","");
   str = "Mex$ " + str;
    console.log("Precio en EPIC: " + str);
  browser.close();

   const gameInfo = {
       SteamPrice: steamPrice,
       EpicPrice : str,
       foto: imagen,
       fecha: fecha,
       titulo: tituloG,
       resena: b,
       requisitos: rets,
       urlEpic : "https://www.epicgames.com" + getGame,
       urlSteam: enlace,
   }
   return gameInfo;

}

app.listen(port, () => console.log("Example app listening on port ${port}!"));
