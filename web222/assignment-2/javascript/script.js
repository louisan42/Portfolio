


const activePage = () => {
  let pageLoad = document.getElementById("menu").getElementsByTagName("a");
  for(let i=0;i < pageLoad.length; i++) {
      pageLoad[i].addEventListener("click", function()  {
        let currentPage = document.getElementsByClassName("activePage");
        if(currentPage.length > 0){
            currentPage[0].className = currentPage[0].className.replace("activePage", "");
        }
          this.className += "activePage";
        });
  
  };
};

window.onload = activePage;

const reloadPage = () => {
  if (!alert("Sorry for not being able to do business with you!")) {
    window.location.reload();
  }
};

let cancelBtn = document.getElementById("cancelBtn");
cancelBtn.addEventListener("click", reloadPage);

const thankUMessage = () => {
  alert("Thank you for your business");
};

let orderBtn = document.getElementById("orderBtn");
orderBtn.addEventListener("click", thankUMessage);

const fNumericCharactersOnly = event => {
  return event.charCode === 0 || /\d/.test(String.fromCharCode(event.charCode));
};

const inputField = document.querySelectorAll("input");
inputField.forEach((inputItem) => {
  inputItem.onkeypress = () => {
    return fNumericCharactersOnly(event);
  };
  inputItem.onpaste = event => false;
});