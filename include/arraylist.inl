/**
 * ArrayList class implementation.
 *
 */

#include "arraylist.h"

/**
 * ---------------------------------------------------------------------------
 * Common methods from ArrayList.
 * ---------------------------------------------------------------------------
 */

// Construtor inicializa TAD.
template < typename Key, typename Data >
ArrayList<Key,Data>::ArrayList ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[ArrayList()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}
template < typename Key, typename Data >
int ArrayList<Key,Data>::_search( Key _x ) const{
	auto i(0);
	for(; i < mi_Length && mpt_Data[i].id != _x ; i++){
	}
		return i;
	}
 template < typename Key, typename Data >
 bool ArrayList<Key,Data>::remove( Key _x, Data & _recovdata){
 	if(mi_Length == 0){
 		throw std::invalid_argument( "[ArrayList()]: Underflow (Lista Vazia)!" );
 	}
 	else{
 		auto p(0);
 		p = ArrayList::_search(_x);
 		if(p == mi_Length){
 			throw std::invalid_argument( "[ArrayList::remove]: Elemento não encontrado!" );
 		}
 		else{
 			_recovdata = mpt_Data[p].info;
 			for(auto i(p); i < mi_Length; i++){
 				mpt_Data[i].id = mpt_Data[i+1].id;
 				mpt_Data[i].info = mpt_Data[i+1].info;
 			}
 		}
 			mi_Length--;
 			return true;
 	}
}
 template < typename Key, typename Data >
 bool ArrayList<Key,Data>::search( Key _x, Data & ) const{
 	auto p(0);
 	p = ArrayList::_search(_x);
 	if(p == mi_Length){
 		return false;
 	}
 	else{
 		return true;
 	}
 }
 template < typename Key, typename Data >
 bool ArrayList<Key,Data>::insert( Key _novaId, Data _novaInfo ){
 	if(mi_Length == mi_Capacity){
 		throw std::invalid_argument( "[ArrayList::insert]: Overflow (Lista Cheia)!" );
 	}
 	auto p(0);
 	p = ArrayList::_search(_novaId);
 	if(p == mi_Length){
 		mpt_Data[p].id = _novaId;
 		mpt_Data[p].info = _novaInfo;
 		mi_Length++;
 		return true;
 	}
 	else{
 		return false;
 	}
 }

