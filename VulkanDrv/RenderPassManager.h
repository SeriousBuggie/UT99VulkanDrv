#pragma once

class UVulkanRenderDevice;

class RenderPassManager
{
public:
	RenderPassManager(UVulkanRenderDevice* renderer);
	~RenderPassManager();

	std::unique_ptr<VulkanPipelineLayout> ScenePipelineLayout;
	std::unique_ptr<VulkanPipelineLayout> SceneBindlessPipelineLayout;
	std::unique_ptr<VulkanPipelineLayout> PresentPipelineLayout;

	void CreateRenderPass();
	void CreatePipelines();

	void CreatePresentRenderPass();
	void CreatePresentPipeline();

	void BeginScene(VulkanCommandBuffer* cmdbuffer);
	void EndScene(VulkanCommandBuffer* cmdbuffer);

	void BeginPresent(VulkanCommandBuffer* cmdbuffer);
	void EndPresent(VulkanCommandBuffer* cmdbuffer);

	VulkanPipeline* getPipeline(DWORD polyflags, bool bindless);
	VulkanPipeline* getEndFlashPipeline();

	std::unique_ptr<VulkanRenderPass> SceneRenderPass;

	std::unique_ptr<VulkanRenderPass> PresentRenderPass;
	std::unique_ptr<VulkanPipeline> PresentPipeline;

private:
	void CreateScenePipelineLayout();
	void CreateSceneBindlessPipelineLayout();
	void CreatePresentPipelineLayout();

	UVulkanRenderDevice* renderer = nullptr;
	std::unique_ptr<VulkanPipeline> pipeline[2][32];
};
