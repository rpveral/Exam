var NativeExtension = require('bindings')('NativeExtension');
module.exports = NativeExtension;

console.log("Number of Monitors: " + NativeExtension.monitor());
console.log("Last Input Time: " + NativeExtension.lastinputtime() + " seconds");
setTimeout(() => { console.log("Screen Sleep"); }, 1000);
NativeExtension.displaysleep();
setTimeout(() => { console.log("Screen Wake up"); }, 2000);
NativeExtension.displaywake();