//===========================================================================
//! @file   filter_manager.h
//!	@brief	�`��Ɏg�p����t�B���^�[�Ǘ�
//===========================================================================
#pragma once

//===========================================================================
//!	@class FilterManager
//===========================================================================
class FilterManager
{
public:
    //-----------------------------------------------------------------------
    //!	@name	������
    //-----------------------------------------------------------------------
    //@{

    //! @brief �R���X�g���N�^
    FilterManager() = default;

    //! @brief �f�X�g���N�^
    ~FilterManager() = default;

    //@}
    //-----------------------------------------------------------------------
    //!	@name	�^�X�N
    //-----------------------------------------------------------------------
    //@{

    //-----------------------------------------------------------------------
    //! @brief ������
    //! @return true  ����I��
    //! @return false �G���[�I��
    //-----------------------------------------------------------------------
    bool initialize();

    //! @brief �t�B���^�X�V
    void begin();

    //! @brief ���
    void cleanup();

    //! @brief �A�v�����Ŏg�p���Ă���t�B���^�J��
    void appFilterCleanup();

    //@}
    //-----------------------------------------------------------------------
    //!	@name	�ݒ�
    //-----------------------------------------------------------------------
    //@{

    //-----------------------------------------------------------------------
    //! @brief �g�p����t�B���^�ݒ�
    //!	@param	[in]	filterType	�g�p�������t�B���^�^�C�v
    //-----------------------------------------------------------------------
    void setFilter(FilterType filterType);

    //-----------------------------------------------------------------------
    //! @brief �g�p����t�B���^����
    //!	@param	[in]	filterType	�폜�������t�B���^�^�C�v
    //-----------------------------------------------------------------------
    void removeFilter(FilterType filterType);

    //@}
    //-----------------------------------------------------------------------
    //!	@name	�擾
    //-----------------------------------------------------------------------
    //@{

	//-----------------------------------------------------------------------
    //! @brief HDR�����ǂ���
	//! @return true   HDR�L��
	//! @return false  HDR����
	//-----------------------------------------------------------------------
    bool isHDR() const;

    //@}

private:
    //-----------------------------------------------------------------------
    //!	@name	�ǉ�
    //-----------------------------------------------------------------------
    //@{

    //-----------------------------------------------------------------------
    //! @brief �t�B���^�ǉ�
    //!	@param	[in]	filterType	�z��ɒǉ�����t�B���^�^�C�v
    //-----------------------------------------------------------------------
    void addFilter(FilterType filterType);

    //! @brief �K�E�V�A���ڂ����t�B���^�쐬
    Filter* createGaussianBlur();

    //! @brief �g�[���}�b�s���O�t�B���^�쐬
    Filter* createToneMapping();

    //@}

private:
    std::list<std::shared_ptr<Filter>> filters_;         //!< �ۑ��p
    std::list<std::weak_ptr<Filter>>   appUsefilters_;   //!< �A�v�����Ŏg���t�B���^

    // �Ȃ�������
    bool isHDR_ = true;
};