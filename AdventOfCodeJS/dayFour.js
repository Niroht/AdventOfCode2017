export function BasicPassphraseValidate(input){
    let groups = input
    .match(/\S+/g)
    .reduce((foundPieces, currentPiece) => {
        let matchingPiece = foundPieces.find(x => x.value === currentPiece);
        if (!matchingPiece) {
            foundPieces.push({ count: 1, value: currentPiece});
        }
        else {
            matchingPiece.count++;
        }
        return foundPieces;
    }, []);
    return !groups.find(x => x.count > 1);
}

export function ComplexPassphraseValidate(input){
    let groups = input
    .match(/\S+/g)
    .map(x => x.split('').sort().join(''))
    .reduce((foundPieces, currentPiece) => {
        let matchingPiece = foundPieces.find(x => x.value === currentPiece);
        if (!matchingPiece) {
            foundPieces.push({ count: 1, value: currentPiece});
        }
        else {
            matchingPiece.count++;
        }
        return foundPieces;
    }, []);
    return !groups.find(x => x.count > 1);
}