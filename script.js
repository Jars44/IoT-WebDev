const endpoint = "http://192.168.1.4";

function getTidurLed() {
  fetch(endpoint + "/tidur", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledTidur.style.backgroundColor = "#579fff";
        ledTidur.innerHTML = "TURN OFF";
        tidurLedImage.src = "./assets/led-on.png";
      } else {
        ledTidur.style.backgroundColor = "red"; 
        tidurLedImage.src = "./assets/led-off.png";
      }
    });
}

function getTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledTamu.style.backgroundColor = "#579fff";
        tamuLedImage.src = "./assets/led-on.png";
        ledTamu.innerHTML = "TURN OFF";
      } else {
        ledTamu.style.backgroundColor = "red";
        tamuLedImage.src = "./assets/led-off.png";
      }
    });
}

function getMakanLed() {
  fetch(endpoint + "/makan", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledMakan.style.backgroundColor = "#579fff";
        ledMakan.innerHTML = "TURN OFF";
        makanLedImage.src = "./assets/led-on.png";
      } else {
        ledTidur.style.backgroundColor = "red";
        makanLedImage.src = "./assets/led-off.png";
      }
    });
}

function getKeluargaLed() {
  fetch(endpoint + "/keluarga", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledKeluarga.style.backgroundColor = "#579fff";
        ledKeluarga.innerHTML = "TURN OFF";
        keluargaLedImage.src = "./assets/led-on.png";
      } else {
        ledKeluarga.style.backgroundColor = "red";
        keluargaLedImage.src = "./assets/led-off.png";
      }
    });
}

function setTidurLed() {
  fetch(endpoint + "/tidur", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => location.reload());

  ledTidur.style.backgroundColor = "#579fff";
  tidurLedImage.src = "./assets/led-on.png";
}
function setTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => location.reload());

  ledTamu.style.backgroundColor = "#579fff";
  tamuLedImage.src = "./assets/led-on.png";
}
function setMakanLed() {
  fetch(endpoint + "/makan", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => location.reload());

  ledMakan.style.backgroundColor = "#579fff";
  makanLedImage.src = "./assets/led-on.png";
}
function setKeluargaLed() {
  fetch(endpoint + "/keluarga", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => location.reload());

  ledKeluarga.style.backgroundColor = "#579fff";
  keluargaLedImage.src = "./assets/led-on.png";
}

getTidurLed();
getTamuLed();
getMakanLed();
getKeluargaLed();