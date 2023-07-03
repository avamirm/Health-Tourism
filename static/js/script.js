"use strict";

const openHamburgerMenuIcon = document.getElementById("open-hamburger-icon");
const closeHamburgerMenuIcon = document.getElementById("close-hamburger-icon");
const responsiveNavEl = document.getElementById("nav-responsive");
const searchTagDeleteIcons = document.querySelectorAll(".search-tag__delete");
const categoriesEls = document.querySelectorAll(".popular__categories > li");
const themeTogglerEl = document.getElementById("theme-color-toggler");
const themeTogglerEl2 = document.getElementById("theme-color-toggler-2");

function callbackFunc(entries, observer) {
  entries.forEach((entry) => {
    let tempEl = entry.target;
    let tempElAnimate = entry.target.getAttribute("data-animate");

    entry.isIntersecting
      ? tempEl.classList.add(tempElAnimate)
      : tempEl.classList.remove(tempElAnimate);
  });
}

let options = {
  root: null,
  rootMargin: "0px",
  threshold: 0.3,
};

let observer = new IntersectionObserver(callbackFunc, options);

observer.observe(document.getElementById("steps-img-1"));
observer.observe(document.getElementById("steps-img-2"));
observer.observe(document.getElementById("why-img-1"));
observer.observe(document.getElementById("why-img-2"));
observer.observe(document.getElementById("feedback-img-1"));

openHamburgerMenuIcon.addEventListener("click", function () {
  responsiveNavEl.classList.remove("nav--responsive--hidden");
});

function closeHamburgerMenu() {
  responsiveNavEl.classList.add("nav--responsive--hidden");
}

closeHamburgerMenuIcon.addEventListener("click", closeHamburgerMenu);

searchTagDeleteIcons.forEach((el) => {
  el.addEventListener("click", function () {
    console.log(el.parentElement.remove());
  });
});

categoriesEls.forEach((el) => {
  el.addEventListener("click", function () {
    document.querySelectorAll(".popular__items").forEach((el) => {
      el.classList.add("d-none");
    });
    categoriesEls.forEach((el) => {
      el.classList.remove("active-category");
      el.classList.remove("btn--primary");
    });

    el.classList.add("active-category");
    el.classList.add("btn--primary");
    let classTarget = document.querySelector(
      `.${el.getAttribute("data-target")}`
    );
    classTarget.classList.remove("d-none");
  });
});

function toggleTheme() {
  document.querySelector("body").classList.toggle("dark");
  const logoEls = document.querySelectorAll(".header__logo");
  if (document.querySelector("body").classList.contains("dark")) {
    if (this.classList.contains("nav__item")) {
      this.querySelector("a").textContent = "Dark Mode";
    }

    logoEls.forEach((el) => {
      el.setAttribute("src", "assets/WeCare-Logo-dark.png");
    });
  } else {
    if (this.classList.contains("nav__item")) {
      this.querySelector("a").textContent = "Light Mode";
    }
    logoEls.forEach((el) => {
      el.setAttribute("src", "assets/WeCare-Logo.png");
    });
  }
}

themeTogglerEl.addEventListener("click", toggleTheme);
themeTogglerEl2.addEventListener("click", toggleTheme);
