/*User java work*/
const wrapper = document.querySelector(".wrapper");
const loginLink = document.querySelector(".login-link");
const registerLink = document.querySelector(".register-link");

registerLink.addEventListener("click", ()=> {
    wrapper.classList.add("active");
});

loginLink.addEventListener("click", ()=> {
    wrapper.classList.remove("active");
});

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