/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var current = init;

    function increment(){
        return current = current + 1;
    }
    function decrement(){
        return current = current - 1;
    }
    function reset(){
        return current = init;
    }
    return{increment , decrement , reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */