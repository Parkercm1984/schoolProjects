var java,browserPlat, browserCode, browserName, browserVer, person,name,age,gender;
var yearsLeft = 0;
java = navigator.javaEnabled();
browserPlat = navigator.platform;
browserCode = navigator.appCodeName;
browserName = navigator.appName;
browserVer = navigator.appVersion;
name = prompt("What is your name?","");
age = prompt("What is your age?","");
gender = prompt("What is your gender? (m/f)","");

while (gender !== "M"&& gender!=="F"&&gender !== "m"&& gender!=="f"){
if (gender !== "M"&& gender!=="F"&&gender !== "m"&& gender!=="f"){
	alert("Please enter (M/F) for your gender");
	gender = prompt("What is your gender? (m/f)","");
}
}//end while loop

person = {Name: name,Age: age, Gender: gender,};

person.life_expect = function(age,gender) {
	
	if (gender == "M" || gender == "m"){
		yearsLeft = 76 - age; 
	}
	else{
		yearsLeft = 81 - age;
	}
	return yearsLeft;
};



if (java = true){
	document.write("<p><br>Java is enabled!");
}
else {
	document.write("<p><br>Java is not enabled!");
}
document.write("<br>Browser platform: " + browserPlat);
document.write("<br>Browser code name: " + browserCode);
document.write("<br>Browse name: " + browserName);
document.write("<br>Browser version: " + browserVer);
document.write("<p><br>Person's Properties:");
with(person){
	document.write("<br>"+ name);
	document.write("<br>"+ age);
	document.write("<br>"+ gender);
	document.write("<br>"+ life_expect(age,gender));
	if (gender == "M" || gender == "m"){
		document.write("<p>Hi " +name +", as a " + age + " year old male you are expected to live " + life_expect(age,gender) + " more years!");
	
	}
	else{
	document.write("<p>Hi " +name +", as a " + age + " year old female you are expected to live " + life_expect(age,gender) + " more years!");
	}}
