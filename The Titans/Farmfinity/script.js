/*Search form*/
let searchForm = document.querySelector(".search-form");

document.querySelector("#search").onclick = () =>{
    searchForm.classList.toggle("active");
    Cart.classList.remove("active");
    navlinks.classList.remove("active");
}

/*Checkout btn*/
let Cart = document.querySelector(".cart");

document.querySelector("#cart").onclick = () =>{
    Cart.classList.toggle("active");
    searchForm.classList.remove("active");
    navlinks.classList.remove("active");
}

window.onscroll = () =>{
    searchForm.classList.remove("active");
    Cart.classList.remove("active");
    navlinks.classList.remove("active");
}

/*Menu bar java work*/
const navlinks = document.querySelector(".nav-links");
const Menu = document.querySelector("#menu");
const X = document.querySelector("#X");

Menu.addEventListener("click", ()=> {
    navlinks.classList.add("active");
    searchForm.classList.remove("active");
    Cart.classList.remove("active");
});

X.addEventListener("click", ()=> {
    navlinks.classList.remove("active");
});

/*Sticky Navbar*/
window.addEventListener("scroll", function(){
    var navbar = document.querySelector(".navbar");
    navbar.classList.toggle("sticky", window.scrollY > 0);
})